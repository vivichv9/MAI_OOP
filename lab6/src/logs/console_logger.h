#ifndef LAB6_CONSOLE_LOGGER_H
#define LAB6_CONSOLE_LOGGER_H

#include "interface/Log.h"
#include "iostream"

namespace lab6 {

class ConsoleLogger : public Log {
public:
  void create_log(lab6::LOGType log_type, const std::string& signature) override;

};
}


#endif // LAB6_CONSOLE_LOGGER_H
