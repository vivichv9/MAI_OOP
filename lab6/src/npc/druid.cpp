#include "include/druid.h"

void lab6::Druid::attack() {
  NPC::notify(this->name, this->state);
}

lab6::Druid::Druid(const std::string& name, const lab6::Square& npc_field,
                   lab6::NPCType type, lab6::NPCStatus state) : NPC(name, npc_field, type, state) {

}
