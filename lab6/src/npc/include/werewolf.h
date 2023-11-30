#ifndef WEREWOLF_H_INCLUDED
#define WEREWOLF_H_INCLUDED

#include "npc.h"

namespace lab6 {

class Werewolf : NPC {
public:
  Werewolf(const std::string& name, const Square& npc_field, size_t atack_range, NPCStatus state = NPCStatus::ORDINARY);

  void attack() override;
};

}

#endif