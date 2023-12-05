#include "include/squirrel.h"

lab6::Squirrel::Squirrel(const std::string& name, const lab6::Square& npc_field,
                         NPCType type, NPCStatus state) : NPC(name, npc_field, type, state) {

}

void lab6::Squirrel::attack() {
  NPC::notify(this->name, this->state);
}
