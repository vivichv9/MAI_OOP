#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "field/square.h"
#include "enums/npc_status.h"
#include "observer/interface/IObservable.h"
#include "observer/interface/IObserver.h"
#include "enums/npc_type.h"
#include "visitor/visitor.h"

#include <string>
#include <memory>
#include <vector>

namespace lab6 {

class Visitor;

class NPC {
protected:
  std::string name;
  Square npc_field;
  NPCStatus state;
  NPCType type;

public:
  NPC(std::string name, const Square& npc_field, NPCType type, NPCStatus state = NPCStatus::LIVE);

  virtual void attack(Visitor* v, NPC* npc, double attack_range, std::function<void(LOGType, const std::string&)>& log);

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