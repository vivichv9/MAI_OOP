#ifndef DRUID_H_INCLUDED
#define DRUID_H_INCLUDED

#include "npc.h"

namespace lab6 {

class Druid : public NPC {
public:
  Druid(const std::string& name, const Square& npc_field, size_t atack_range, NPCStatus state = NPCStatus::ORDINARY);
  void attack() override;
};

}

#endif