#ifndef LAB6_IOBSERVER_H
#define LAB6_IOBSERVER_H

#include "enums/npc_status.h"
#include "enums/npc_type.h"
#include "enums/log_type.h"
#include "string"

namespace lab6 {

class IObserver {
public:
  virtual void log(LOGType log_type, const std::string& signature) = 0;
};

}

#endif // LAB6_IOBSERVER_H
