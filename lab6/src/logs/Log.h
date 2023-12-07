#ifndef LAB6_LOG_H
#define LAB6_LOG_H

#include <string>
#include "enums/log_type.h"
#include "observer/interface/IObserver.h"

namespace lab6 {

class Log : public IObserver {
public:
  virtual void create_log(LOGType log_type, const std::string& signature) = 0;

  void log(LOGType log_type, const std::string& signature) override;
};

}

#endif //LAB6_LOG_H
