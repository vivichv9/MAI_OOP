#ifndef LAB6_IOBSERVABLE_H
#define LAB6_IOBSERVABLE_H

#include "IObserver.h"

namespace lab6 {

class IObservable {
public:
  virtual void add_observer(IObserver* o) = 0;
  virtual void remove_observer(IObserver* o) = 0;

  virtual void notify() = 0;
  virtual ~IObservable() = default;
};

}

#endif //LAB6_IOBSERVABLE_H
