#include "include/druid.h"

lab6::Druid::Druid(const std::string& name, const lab6::Square& npc_field,
                   lab6::NPCType type, lab6::NPCStatus state) : NPC(name, npc_field, type, state) {}
