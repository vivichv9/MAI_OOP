#ifndef LAB6_FILE_LOGGER_H
#define LAB6_FILE_LOGGER_H

#include "Log.h"
#include "fstream"
#include "termcolor/termcolor.hpp"

namespace lab6 {

class FileLogger : public Log {
private:
  std::ofstream file;

public:
  explicit FileLogger(const std::string& file_name);

  virtual ~FileLogger();

  void create_log(lab6::LOGType log_type, const std::string& signature) override;
};

}

#endif //LAB6_FILE_LOGGER_H
