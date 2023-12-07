#ifndef LAB6_IOBSERVABLE_H
#define LAB6_IOBSERVABLE_H

#include <vector>
#include "IObserver.h"
#include "enums/log_type.h"

namespace lab6 {

class IObservable {
public:
  virtual void add_observer(IObserver* o) = 0;

  virtual void remove_observer(IObserver* o) = 0;

  virtual void notify(LOGType log_type, const std::string& signature) = 0;
};

}

#endif
