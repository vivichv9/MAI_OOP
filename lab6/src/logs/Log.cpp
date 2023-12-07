#include "logs/Log.h"

void lab6::Log::log(LOGType log_type, const std::string& signature) {
  create_log(log_type, signature);
}
