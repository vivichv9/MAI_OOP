#ifndef LAB6_IOBSERVABLE_H
#define LAB6_IOBSERVABLE_H

#include <vector>
#include "IObserver.h"

namespace lab6 {

class IObservable {
protected:
  std::vector<IObserver*> observers;

public:
  virtual void add_observer(IObserver* o) = 0;

  virtual void remove_observer(IObserver* o) = 0;

  virtual void notify(const std::string& name, NPCStatus status) = 0;
};

}

#endif
