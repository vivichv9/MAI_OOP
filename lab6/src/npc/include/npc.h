#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "../../field/square.h"
#include "../../enums/npc_status.h"
#include "observer/interface/IObservable.h"
#include "enums/npc_type.h"
#include <string>
#include <memory>
#include <vector>

namespace lab6 {

class NPC : public IObservable {
protected:
  std::vector<std::shared_ptr<IObserver>> observers;
  std::string name;
  Square npc_field;
  size_t attack_range;
  NPCStatus state;
  NPCType type;

public:
  NPC(std::string  name, const Square& npc_field, size_t attack_range, NPCType type, NPCStatus state = NPCStatus::ORDINARY);
  virtual void attack() = 0;
  virtual void change_state(NPCStatus state) = 0;
};

}

#endif