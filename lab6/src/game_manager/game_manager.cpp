#include "game_manager.h"

void lab6::GameManager::game_controller() {
  auto ptr = factory::create_npc(SQUIRREL, "bebrow", Square(12, 123), 11);

  npc_table.insert({"bebrow", ptr});
}
