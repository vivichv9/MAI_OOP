#ifndef LAB6_GAME_MANAGER_H
#define LAB6_GAME_MANAGER_H

#include <unordered_map>
#include <memory>
#include "npc/include/npc.h"
#include "field/square.h"
#include "factory/NPCFactory.h"

namespace lab6 {

class GameManager : public IObservable {
private:
  NPCFactory factory;
  std::unordered_map<std::string, std::shared_ptr<NPC>> npc_table;
  std::vector<IObserver*> observers;

  void attack_cycle(double attack_range);

public:
  GameManager() = default;

  void add_observer(IObserver* o) override;

  void remove_observer(IObserver* o) override;

  void notify(LOGType log_type, const std::string& signature) override;

  void game_controller();
};


}

#endif //LAB6_GAME_MANAGER_H
