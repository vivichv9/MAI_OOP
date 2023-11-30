#include "logger.h"

using namespace lab6;

Logger::Logger(const std::string& output_file_name) {
  file.open(output_file_name);
}

Logger::~Logger() {
  file.close();
}

void Logger::create_log(LOGType log_type, const std::string& log_signature) {
  switch (log_type) {
    case INFO:
      file << "[ INFO ]: " << log_signature << std::endl;
      break;

    case WARNING:
      file << "[ WARNING ]: " << log_signature << std::endl;
      break;

    case ERROR:
      file << "[ ERROR ]: " << log_signature << std::endl;
      break;

    default:
      throw std::invalid_argument("Unknown log_type");
  }
}
