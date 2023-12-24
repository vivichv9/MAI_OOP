#include "squirrel.hpp"
#include "druid.hpp"
#include "werewolf.hpp"

Squirrel::Squirrel(int x, int y) : NPC(SquirrelType, x, y) {}

Squirrel::Squirrel(std::istream& is) : NPC(SquirrelType, is) {}

void Squirrel::print() {
  std::cout << *this;
}

bool Squirrel::accept(std::shared_ptr<NPC> visitor) {
  return visitor->fight(std::shared_ptr<Squirrel>(this, [](Squirrel*) {}));
}

void Squirrel::save(std::ostream& os) {
  os << SquirrelType << std::endl;
  NPC::save(os);
}

bool Squirrel::fight(std::shared_ptr<Werewolf> other) {
  fight_notify(other, true);
  return true;
}

bool Squirrel::fight(std::shared_ptr<Squirrel> other) {
  fight_notify(other, false);
  return false;
}

bool Squirrel::fight(std::shared_ptr<Druid> other) {
  fight_notify(other, true);
  return true;
}

std::ostream& operator<<(std::ostream& os, Squirrel& Squirrel) {
  os << "Squirrel: " << *static_cast<NPC*>(&Squirrel) << std::endl;
  return os;
}