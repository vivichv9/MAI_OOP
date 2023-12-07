#include "visitor.h"

#include "npc/include/npc.h"

using namespace lab6;

void Visitor::visit(NPC* npc1, NPC* npc2, double attack_range, std::function<void(LOGType, const std::string&)>& log) {
  if (npc1 == nullptr || npc2 == nullptr) {
    log(WARNING, "nullptr argument in function GameManager::attack");
    return;
  }

  if (npc1->getState() == DEAD || npc2->getState() == DEAD) {
    return;
  }

  if (attack_range >= Square::len(npc1->getNpcField(), npc2->getNpcField())) {
    if (npc1->getType() == SQUIRREL && npc2->getType() == SQUIRREL) {
      log(INFO, "MURDER: " + npc2->getName() + " killed by " + npc1->getName());
      npc2->setState(DEAD);
      return;
    }

    if (npc1->getType() == SQUIRREL && npc2->getType() != SQUIRREL) {
      log(INFO, "MURDER: " + npc2->getName() + " killed by " + npc1->getName());
      npc2->setState(DEAD);
      return;
    }

    if (npc1->getType() != SQUIRREL && npc2->getType() == SQUIRREL) {
      log(INFO, "MURDER: " + npc1->getName() + " killed by " + npc2->getName());
      npc1->setState(DEAD);
      return;
    }

    if (npc1->getType() == WEREWOLF && npc2->getType() == WEREWOLF) {
      log(INFO, "MURDER: " + npc2->getName() + " killed by " + npc1->getName());
      npc2->setState(DEAD);
      return;
    }

    if (npc1->getType() == WEREWOLF && npc2->getType() == DRUID) {
      log(INFO, "MURDER: " + npc2->getName() + " killed by " + npc1->getName());
      npc2->setState(DEAD);
      return;
    }

    if (npc1->getType() == DRUID && npc2->getType() == WEREWOLF) {
      log(INFO, "MURDER: " + npc1->getName() + " killed by " + npc2->getName());
      npc1->setState(DEAD);
      return;
    }

    if (npc1->getType() == DRUID && npc2->getType() == DRUID) {
      return;
    }
  }
}
