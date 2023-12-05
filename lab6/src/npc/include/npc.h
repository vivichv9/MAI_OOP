#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "../../field/square.h"
#include "../../enums/npc_status.h"
#include "../../observer/interface/IObservable.h"
#include "../../observer/interface/IObserver.h"
#include "../../enums/npc_type.h"
#include "../../visitor/visitor.h"

#include <string>
#include <memory>
#include <vector>

namespace lab6 {

class NPC : public IObservable {
protected:
  std::string name;
  Square npc_field;
  double attack_range = 15.0;
  NPCStatus state;
  NPCType type;

public:
  NPC(std::string  name, const Square& npc_field, NPCType type, NPCStatus state = NPCStatus::LIVE);

  // virtual void accept(Visitor& visitor);

  void add_observer(IObserver* o) override;
  void remove_observer(IObserver* o) override;
  void notify(const std::string& name, NPCStatus status) override;
  virtual void attack() = 0;

  const std::string &getName() const;

  void setName(const std::string &name);

  const Square &getNpcField() const;

  void setNpcField(const Square &npcField);

  double getAttackRange() const;

  void setAttackRange(size_t attackRange);

  NPCStatus getState() const;

  void setState(NPCStatus state);

  NPCType getType() const;

  void setType(NPCType type);
};

}

#endif