#ifndef LAB6_CONSOLE_LOGGER_H
#define LAB6_CONSOLE_LOGGER_H

#include "Log.h"
#include "iostream"
#include "termcolor/termcolor.hpp"

namespace lab6 {

class ConsoleLogger : public Log {
public:
  void create_log(lab6::LOGType log_type, const std::string& signature) override;

  virtual ~ConsoleLogger() = default;
};
}

#endif // LAB6_CONSOLE_LOGGER_H
