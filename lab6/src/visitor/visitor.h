#ifndef LAB6_VISITOR_H
#define LAB6_VISITOR_H

#include <functional>
#include "npc/include/npc.h"

namespace lab6 {

class NPC;

class Visitor {
public:
  Visitor() = default;
  virtual ~Visitor() = default;

  virtual void visit(NPC* npc1, NPC* npc2, double attack_range, std::function<void(LOGType, const std::string&)>& log);
};

}

#endif //LAB6_VISITOR_H
