#include "logger.h"

using namespace lab6;

Logger::Logger(const std::string& output_file_name) {
  file.open(output_file_name);
}

Logger::~Logger() {
  file.close();
}