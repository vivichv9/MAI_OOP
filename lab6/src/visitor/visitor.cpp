#include "visitor.h"

#include "npc/include/npc.h"

using namespace lab6;

void Visitor::visit(NPC* npc1, NPC* npc2, double attack_range, NPCLogger& logger) {
  if (npc1 == nullptr || npc2 == nullptr) {
    logger.system_log(WARNING, "nullptr argument in function GameManager::attack");
    return;
  }

  if (npc1->getState() == DEAD || npc2->getState() == DEAD) {
    return;
  }

  if (attack_range >= Square::len(npc1->getNpcField(), npc2->getNpcField())) {
    if (npc1->getType() == SQUIRREL && npc2->getType() == SQUIRREL) {
      logger.kill(npc1->getName(), npc2->getName());
      npc2->setState(DEAD);
      return;
    }

    if (npc1->getType() == SQUIRREL && npc2->getType() != SQUIRREL) {
      logger.kill(npc1->getName(), npc2->getName());
      npc2->setState(DEAD);
      return;
    }

    if (npc1->getType() != SQUIRREL && npc2->getType() == SQUIRREL) {
      logger.kill(npc2->getName(), npc1->getName());
      npc1->setState(DEAD);
      return;
    }

    if (npc1->getType() == WEREWOLF && npc2->getType() == WEREWOLF) {
      logger.kill(npc1->getName(), npc2->getName());
      npc2->setState(DEAD);
      return;
    }

    if (npc1->getType() == WEREWOLF && npc2->getType() == DRUID) {
      logger.kill(npc1->getName(), npc2->getName());
      npc2->setState(DEAD);
      return;
    }

    if (npc1->getType() == DRUID && npc2->getType() == WEREWOLF) {
      logger.kill(npc2->getName(), npc1->getName());
      npc1->setState(DEAD);
      return;
    }

    if (npc1->getType() == DRUID && npc2->getType() == DRUID) {
      return;
    }
  }
}
