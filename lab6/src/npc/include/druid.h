#ifndef DRUID_H_INCLUDED
#define DRUID_H_INCLUDED

#include "npc.h"

namespace lab6 {

class Druid final : public NPC {
public:
  Druid(const std::string& name, const lab6::Square& npc_field,
        NPCType type, NPCStatus state = LIVE);

  void attack() override;
};

}

#endif