#include <functional>
#include "game_manager.h"

using namespace lab6;

void GameManager::game_controller() {
  attack_cycle(100);
  attack_cycle(200);
  attack_cycle(11100);
  attack_cycle(101230);
}

void GameManager::attack_cycle(double attack_range) {
  Visitor v;

  std::function<void(LOGType, const std::string&)> log([this](LOGType log_type, const std::string& signature) {
    notify(log_type, signature);
  });

  npc_table.clear();
  factory.create_npc_from_file("/home/kirill/Desktop/study/MAI_OOP/lab6/data/npc.txt", npc_table, log);
  notify(INFO, "Attack cycle with attack range: " + std::to_string(attack_range) + " started");
  for (auto& i: npc_table) {
    for (auto& j: npc_table) {
      if (i != j) {
        i.second->attack(&v, j.second.get(), attack_range, log);
      }
    }
  }
}

void GameManager::add_observer(IObserver* o) {
  observers.push_back(o);
}

void GameManager::remove_observer(IObserver* o) {
  observers.erase(std::find(observers.begin(), observers.end(), o));
}

void GameManager::notify(LOGType log_type, const std::string& signature) {
  for (auto& e: observers) {
    e->log(log_type, signature);
  }
}
