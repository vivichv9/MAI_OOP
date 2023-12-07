#ifndef LAB6_VISITOR_H
#define LAB6_VISITOR_H

#include "../logs/npc_logger.h"
#include "npc/include/npc.h"

namespace lab6 {

class NPC;

class Visitor {
public:
  Visitor() = default;
  virtual ~Visitor() = default;

  virtual void visit(NPC* npc1, NPC* npc2, double attack_range, NPCLogger& logger);
};

}

#endif //LAB6_VISITOR_H
