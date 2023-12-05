#include "include/werewolf.h"

lab6::Werewolf::Werewolf(const std::string& name, const lab6::Square& npc_field,
                         NPCType type, NPCStatus state) : NPC(name, npc_field, type, state) {

}

void lab6::Werewolf::attack() {
  NPC::notify(this->name, this->state);
}
