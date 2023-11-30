#ifndef SQUIRELL_H_INCLUDED
#define SQUIRELL_H_INCLUDED

#include "npc.h"

namespace lab6 {

class Squirrel : public NPC {
public:
  Squirrel(const std::string& name, const Square& npc_field, size_t atack_range, NPCStatus state = NPCStatus::ORDINARY);
  void attack() override;
};

}

#endif