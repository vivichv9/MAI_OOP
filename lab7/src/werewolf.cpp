#include "werewolf.hpp"
#include "squirrel.hpp"
#include "druid.hpp"

Werewolf::Werewolf(int x, int y) : NPC(WerewolfType, x, y) {}

Werewolf::Werewolf(std::istream& is) : NPC(WerewolfType, is) {}

bool Werewolf::accept(std::shared_ptr<NPC> visitor) {
  return visitor->fight(std::shared_ptr<Werewolf>(this, [](Werewolf*) {}));
}

void Werewolf::print() {
  std::cout << *this;
}

bool Werewolf::fight(std::shared_ptr<Werewolf> other) {
  fight_notify(other, false);
  return false;
}

bool Werewolf::fight(std::shared_ptr<Squirrel> other) {
  fight_notify(other, false);
  return false;
}

bool Werewolf::fight(std::shared_ptr<Druid> other) {
  fight_notify(other, true);
  return false;
}

void Werewolf::save(std::ostream& os) {
  os << WerewolfType << std::endl;
  NPC::save(os);
}

std::ostream& operator<<(std::ostream& os, Werewolf& Werewolf) {
  os << "Werewolf: " << *static_cast<NPC*>(&Werewolf) << std::endl;
  return os;
}