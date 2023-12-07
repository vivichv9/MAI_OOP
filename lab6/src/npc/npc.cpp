#include <utility>

#include "include/npc.h"

using namespace lab6;

NPC::NPC(std::string name, const Square& npc_field, NPCType type, NPCStatus state)
        : name(std::move(name)), npc_field(npc_field), state(state), type(type) {}

void NPC::add_observer(lab6::IObserver* o) {
  if (o != nullptr) {
    observers.push_back(o);
  }
}

void NPC::remove_observer(lab6::IObserver* o) {
  observers.erase(std::find(observers.begin(), observers.end(), o));
}

void NPC::notify(const std::string& name, NPCStatus status) {
  for (auto& e: observers) {
    e->update(name, status);
  }
}

const std::string& NPC::getName() const {
  return name;
}

void NPC::setName(const std::string& name) {
  NPC::name = name;
}

const Square& NPC::getNpcField() const {
  return npc_field;
}

void NPC::setNpcField(const Square& npcField) {
  npc_field = npcField;
}

NPCStatus NPC::getState() const {
  return state;
}

void NPC::setState(NPCStatus state) {
  NPC::state = state;
}

NPCType NPC::getType() const {
  return type;
}

void NPC::setType(NPCType type) {
  NPC::type = type;
}

void NPC::attack(Visitor* v, NPC* npc, double attack_range, NPCLogger& logger) {
  v->visit(this, npc, attack_range, logger);
}
