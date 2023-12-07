#ifndef LAB6_GAME_MANAGER_H
#define LAB6_GAME_MANAGER_H

#include <unordered_set>
#include <memory>
#include "../npc/include/npc.h"
#include "../field/square.h"
#include "../factory/NPCFactory.h"

namespace lab6 {

class GameManager {
private:
  NPCLogger logger;
  NPCFactory factory;
  std::unordered_set<std::shared_ptr<NPC>> npc_table;

  void attack_cycle(double attack_range);

public:
  explicit GameManager(const std::string& log_file_name);

  void game_controller();
};


}

#endif //LAB6_GAME_MANAGER_H
