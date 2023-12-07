#include "file_logger.h"

void lab6::FileLogger::create_log(lab6::LOGType log_type, const std::string& log_signature) {
  switch (log_type) {
    case INFO:
      file << "[INFO]: " << log_signature << std::endl;
      break;

    case WARNING:
      file << "[WARNING]: " << log_signature << std::endl;
      break;

    case ERROR:
      file << "[ERROR]: " << log_signature << std::endl;
      break;

    default:
      throw std::invalid_argument("Unknown log_type");
  }
}

lab6::FileLogger::FileLogger(const std::string& file_name) {
  file.open(file_name);
}

lab6::FileLogger::~FileLogger() {
  file.close();
}
