#include "include/werewolf.h"

lab6::Werewolf::Werewolf(const std::string& name, const lab6::Square& npc_field,
                         NPCType type, NPCStatus state) : NPC(name, npc_field, type, state) {}