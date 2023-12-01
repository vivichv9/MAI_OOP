#ifndef LAB6_CONSOLE_LOGGER_H
#define LAB6_CONSOLE_LOGGER_H

#include "logs/interface/Log.h"
#include "iostream"

namespace lab6 {

class ConsoleLogger : virtual public Log {
public:
  void create_log(lab6::LOGType log_type, const std::string &signature) override;

};
}


#endif //LAB6_CONSOLE_LOGGER_H
