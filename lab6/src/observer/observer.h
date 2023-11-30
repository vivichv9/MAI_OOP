#ifndef LAB6_OBSERVER_H
#define LAB6_OBSERVER_H

#include <vector>
#include <memory>
#include "npc/include/npc.h"

namespace lab6 {

class Observer {
private:
  std::vector<std::shared_ptr<NPC>> subjects;

public:
  void notify_all();
  void bind(std::shared_ptr<NPC>& npc);
};

}


#endif //LAB6_OBSERVER_H
