#include "game_manager.h"

using namespace lab6;

GameManager::GameManager(const std::string &log_file_name) : factory(log_file_name), logger(log_file_name) {}

void GameManager::game_controller() {
  auto a = factory.create_npc(WEREWOLF, "name", Square(12, 12));
  auto b = factory.create_npc(SQUIRREL, "kuka", Square(13, 13));
  auto c = factory.create_npc(SQUIRREL, "bebra", Square(14, 14));
  auto d = factory.create_npc(SQUIRREL, "qwer", Square(15, 15));
  auto e = factory.create_npc(SQUIRREL, "zzz", Square(16, 16));
  auto f = factory.create_npc(SQUIRREL, "zxc", Square(17, 17));
  auto g = factory.create_npc(SQUIRREL, "rura", Square(18, 18));
  auto h = factory.create_npc(SQUIRREL, "lola", Square(19, 19));
  auto q = factory.create_npc(SQUIRREL, "zola", Square(20, 21));

  a->add_observer(&logger);
  b->add_observer(&logger);
  c->add_observer(&logger);
  d->add_observer(&logger);
  e->add_observer(&logger);
  f->add_observer(&logger);
  g->add_observer(&logger);
  h->add_observer(&logger);
  q->add_observer(&logger);

  npc_table.insert(a);
  npc_table.insert(b);
  npc_table.insert(c);
  npc_table.insert(d);
  npc_table.insert(e);
  npc_table.insert(f);
  npc_table.insert(g);
  npc_table.insert(h);
  npc_table.insert(q);

  for (auto& i : npc_table) {
    for (auto& j : npc_table) {
      if (i != j) {
        attack(i.get(), j.get());
      }
    }
  }
}

void GameManager::attack(NPC *npc1, NPC *npc2) {
  if (npc1 == nullptr || npc2 == nullptr) {
    logger.system_log(WARNING, "nullptr argument in function GameManager::attack");
    return;
  }

  if (npc1->getState() == DEAD || npc2->getState() == DEAD) {
    return;
  }

  if (npc1->getAttackRange() <= Square::len(npc1->getNpcField(), npc2->getNpcField())) {
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
