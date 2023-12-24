#include "druid.hpp"
#include "werewolf.hpp"
#include "squirrel.hpp"

Druid::Druid(int x, int y) : NPC(DruidType, x, y) {}

Druid::Druid(std::istream& is) : NPC(DruidType, is) {}

bool Druid::accept(std::shared_ptr<NPC> visitor) {
  return visitor->fight(std::shared_ptr<Druid>(this, [](Druid*) {}));
}

void Druid::print() {
  std::cout << *this;
}

void Druid::save(std::ostream& os) {
  os << DruidType << std::endl;
  NPC::save(os);
}

bool Druid::fight(std::shared_ptr<Werewolf> other) {
  fight_notify(other, false);
  return true;
}

bool Druid::fight(std::shared_ptr<Squirrel> other) {
  fight_notify(other, false);
  return true;
}

bool Druid::fight(std::shared_ptr<Druid> other) {
  fight_notify(other, false);
  return true;
}

std::ostream& operator<<(std::ostream& os, Druid& Druid) {
  os << "Druid: " << *static_cast<NPC*>(&Druid) << std::endl;
  return os;
}