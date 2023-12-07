#ifndef SQUIRELL_H_INCLUDED
#define SQUIRELL_H_INCLUDED

#include "npc.h"

namespace lab6 {

class Squirrel final : public NPC {
public:
  Squirrel(const std::string& name, const lab6::Square& npc_field,
           NPCType type, NPCStatus state = LIVE);

};
}

#endif