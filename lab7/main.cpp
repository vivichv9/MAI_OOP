#include "npc.hpp"
#include "werewolf.hpp"
#include "squirrel.hpp"
#include "druid.hpp"
#include <sstream>

#include <thread>
#include <mutex>
#include <chrono>
#include <queue>
#include <optional>
#include <array>

using namespace std::chrono_literals;
std::mutex print_mutex;


class TextObserver : public IFightObserver {
private:
  TextObserver() {};

public:
  static std::shared_ptr <IFightObserver> get() {
    static TextObserver instance;
    return std::shared_ptr<IFightObserver>(&instance, [](IFightObserver*) {});
  }

  void on_fight(const std::shared_ptr <NPC> attacker, const std::shared_ptr <NPC> defender, bool win) override {
    if (win) {
      std::lock_guard <std::mutex> lck(print_mutex);
      std::cout << std::endl << "Murder --------" << std::endl;
      attacker->print();
      defender->print();
    }
  }
};

std::shared_ptr <NPC> factory(std::istream& is) {
  std::shared_ptr <NPC> result;
  int type{0};
  if (is >> type) {
    switch (type) {
      case WerewolfType:
        result = std::make_shared<Werewolf>(is);
        break;

      case SquirrelType:
        result = std::make_shared<Squirrel>(is);
        break;

      case DruidType:
        result = std::make_shared<Druid>(is);
        break;
    }
  } else
    std::cerr << "unexpected NPC type:" << type << std::endl;

  if (result) result->subscribe(TextObserver::get());

  return result;
}

std::shared_ptr <NPC> factory(NpcType type, int x, int y) {
  std::shared_ptr <NPC> result;
  switch (type) {
    case WerewolfType:
      result = std::make_shared<Werewolf>(x, y);
      break;
    case SquirrelType:
      result = std::make_shared<Squirrel>(x, y);
      break;
    case DruidType:
      result = std::make_shared<Druid>(x, y);
      break;
    default:
      break;
  }
  if (result)
    result->subscribe(TextObserver::get());

  return result;
}

// save array to file
void save(const set_t& array, const std::string& filename) {
  std::ofstream fs(filename);
  fs << array.size() << std::endl;
  for (auto& n: array)
    n->save(fs);
  fs.flush();
  fs.close();
}

set_t load(const std::string& filename) {
  set_t result;
  std::ifstream is(filename);
  if (is.good() && is.is_open()) {
    int count;
    is >> count;
    for (int i = 0; i < count; ++i)
      result.insert(factory(is));
    is.close();
  } else
    std::cerr << "Error: " << std::strerror(errno) << std::endl;
  return result;
}

std::ostream& operator<<(std::ostream& os, const set_t& array) {
  for (auto& n: array) n->print();
  return os;
}

set_t fight(const set_t& array, size_t distance) {
  set_t dead_list;

  for (const auto& attacker: array)
    for (const auto& defender: array)
      if ((attacker != defender) && attacker->is_close(defender, distance) && defender->accept(attacker))
        dead_list.insert(defender);

  return dead_list;
}

struct print : std::stringstream {
  ~print() {
    static std::mutex mtx;
    std::lock_guard <std::mutex> lck(print_mutex);
    std::cout << this->str();
    std::cout.flush();
  }
};

struct FightEvent {
  std::shared_ptr <NPC> attacker;
  std::shared_ptr <NPC> defender;
};

class FightManager {
private:
  std::queue <FightEvent> events;
  std::shared_mutex mtx;

  FightManager() {}

public:
  static FightManager& get() {
    static FightManager instance;
    return instance;
  }

  void add_event(FightEvent&& event) {
    std::lock_guard <std::shared_mutex> lock(mtx);
    events.push(event);
  }

  void operator()() {
    while (true) {
      {
        std::optional <FightEvent> event;

        {
          std::lock_guard <std::shared_mutex> lock(mtx);
          if (!events.empty()) {
            event = events.back();
            events.pop();
          }
        }

        if (event) {
          try {
            if (event->attacker->is_alive())
              if (event->defender->is_alive())
                if (event->defender->accept(event->attacker))
                  event->defender->must_die();
          }
          catch (...) {
            std::lock_guard <std::shared_mutex> lock(mtx);
            events.push(*event);
          }
        } else
          std::this_thread::sleep_for(100ms);
      }
    }
  }
};

int main() {
  set_t array;

  const int MAX_X{100};
  const int MAX_Y{100};
  const int DISTANCE{40};

  std::cout << "Generating ..." << std::endl;
  for (size_t i = 0; i < 50; ++i)
    array.insert(factory(NpcType(std::rand() % 3 + 1), std::rand() % MAX_X, std::rand() % MAX_Y));

  std::cout << "Starting list:" << std::endl << array;

  std::thread fight_thread(std::ref(FightManager::get()));

  std::thread move_thread([&array]() {
    while (true) {
      for (std::shared_ptr <NPC> npc: array) {
        if (npc->is_alive()) {
          int shift_x = std::rand() % 20 - 10;
          int shift_y = std::rand() % 20 - 10;
          npc->move(shift_x, shift_y, MAX_X, MAX_Y);
        }
      }
      for (std::shared_ptr <NPC> npc: array)
        for (std::shared_ptr <NPC> other: array)
          if (other != npc)
            if (npc->is_alive())
              if (other->is_alive())
                if (npc->is_close(other, DISTANCE))
                  FightManager::get().add_event({npc, other});

      std::this_thread::sleep_for(1s);
    }
  });

  while (true) {
    const int grid{20}, step_x{MAX_X / grid}, step_y{MAX_Y / grid};
    {
      std::array < char, grid * grid > fields{0};
      for (std::shared_ptr <NPC> npc: array) {
        auto [x, y] = npc->position();
        int i = x / step_x;
        int j = y / step_y;

        if (npc->is_alive()) {
          switch (npc->get_type()) {
            case WerewolfType:
              fields[i + grid * j] = 'W';
              break;
            case SquirrelType:
              fields[i + grid * j] = 'S';
              break;
            case DruidType:
              fields[i + grid * j] = 'D';
              break;

            default:
              break;
          }
        } else
          fields[i + grid * j] = '.';
      }

      std::lock_guard <std::mutex> lck(print_mutex);
      for (int j = 0; j < grid; ++j) {
        for (int i = 0; i < grid; ++i) {
          char c = fields[i + j * grid];
          if (c != 0)
            std::cout << "[" << c << "]";
          else
            std::cout << "[ ]";
        }
        std::cout << std::endl;
      }
      std::cout << std::endl;
    }
    std::this_thread::sleep_for(1s);
  };

  move_thread.join();
  fight_thread.join();

  return 0;
}