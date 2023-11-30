#ifndef LAB6_GAME_MANAGER_H
#define LAB6_GAME_MANAGER_H

#include <unordered_map>
#include <memory>
#include "npc/include/npc.h"
#include "logs/logger.h"
#include "field/square.h"
#include "factory/NPCFactory.h"

namespace lab6 {

class GameManager {
private:
  static std::unordered_map<std::string, std::shared_ptr<NPC>> npc_table;

public:
  static void game_controller();
};

}

#endif //LAB6_GAME_MANAGER_H
