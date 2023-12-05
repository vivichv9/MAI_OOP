#ifndef LAB6_IOBSERVER_H
#define LAB6_IOBSERVER_H

#include "../../enums/npc_status.h"
#include "../../enums/npc_type.h"

namespace lab6 {

class IObserver {
public:
  virtual void create(const std::string& name, NPCType type) = 0;
  virtual void kill(const std::string& name1, const std::string& name2) = 0;
  virtual void update(const std::string& name, NPCStatus status) = 0;
};

}

#endif // LAB6_IOBSERVER_H
