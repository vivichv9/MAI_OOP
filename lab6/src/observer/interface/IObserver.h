#ifndef LAB6_IOBSERVER_H
#define LAB6_IOBSERVER_H

#include "enums/npc_status.h"

namespace lab6 {

class IObserver {
public:
  virtual void update(NPCStatus status) = 0;
};

}

#endif // LAB6_IOBSERVER_H
