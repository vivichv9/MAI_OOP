#include "console_logger.h"

using namespace lab6;

void ConsoleLogger::create_log(lab6::LOGType log_type, const std::string& log_signature) {
  switch (log_type) {
    case INFO:
      std::cout << termcolor::green << "[INFO]: " << termcolor::reset << log_signature << std::endl;
      break;

    case WARNING:
      std::cout << termcolor::yellow << "[WARNING]: " << termcolor::reset << log_signature << std::endl;
      break;

    case ERROR:
      std::cout << termcolor::red << "[ERROR]: " << termcolor::reset << log_signature << std::endl;
      break;

    default:
      throw std::invalid_argument("Unknown log_type");
  }
}
