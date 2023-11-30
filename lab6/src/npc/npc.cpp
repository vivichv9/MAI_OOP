#include <utility>

#include "include/npc.h"

lab6::NPC::NPC(std::string name, const lab6::Square& npc_field, size_t attack_range, lab6::NPCStatus state)
  : name(std::move(name)), npc_field(npc_field), attack_range(attack_range), state(state) {}
