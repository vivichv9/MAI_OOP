#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "field/square.h"
#include "enums/npc_status.h"
#include <string>

namespace lab6 {

class NPC {
private:
  std::string name;
  Square npc_field;
  size_t attack_range;
  NPCStatus state;

public:
  NPC(std::string  name, const Square& npc_field, size_t attack_range, NPCStatus state = NPCStatus::ORDINARY);
  virtual void attack() = 0;
};

}

#endif