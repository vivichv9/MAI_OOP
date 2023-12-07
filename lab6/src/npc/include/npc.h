#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "../../field/square.h"
#include "../../enums/npc_status.h"
#include "../../observer/interface/IObservable.h"
#include "../../observer/interface/IObserver.h"
#include "../../enums/npc_type.h"
#include "../../logs/npc_logger.h"
#include "../../visitor/visitor.h"

#include <string>
#include <memory>
#include <vector>

namespace lab6 {

class Visitor;

class NPC : public IObservable {
protected:
  std::string name;
  Square npc_field;
  NPCStatus state;
  NPCType type;

public:
  NPC(std::string name, const Square& npc_field, NPCType type, NPCStatus state = NPCStatus::LIVE);

  virtual void attack(Visitor* v, NPC* npc, double attack_range, NPCLogger& logger);

  void add_observer(IObserver* o) override;

  void remove_observer(IObserver* o) override;

  void notify(const std::string& name, NPCStatus status) override;

  [[nodiscard]] const std::string& getName() const;

  void setName(const std::string& name);

  [[nodiscard]] const Square& getNpcField() const;

  void setNpcField(const Square& npcField);

  [[nodiscard]] NPCStatus getState() const;

  void setState(NPCStatus state);

  [[nodiscard]] NPCType getType() const;

  void setType(NPCType type);
};

}

#endif