#ifndef LOGGER_H_INCLUDED
#define LOGGER_H_INCLUDED

#include <string>
#include <fstream>

#include "enums/log_type.h"

namespace lab6 {

class Logger {
private:
  std::ofstream file;

public:
  explicit Logger(const std::string& output_file_name);
  virtual ~Logger();

  void create_log(LOGType log_type, const std::string& log_signature);
};
  
} // namespace lab6


#endif