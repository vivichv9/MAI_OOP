#ifndef WEREWOLF_H_INCLUDED
#define WEREWOLF_H_INCLUDED

#include "npc.h"

namespace lab6 {

class Werewolf final : public NPC {
public:
  Werewolf(const std::string& name, const lab6::Square& npc_field,
           NPCType type, NPCStatus state = LIVE);
};

}

#endif