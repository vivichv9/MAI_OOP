#ifndef LAB6_NPC_LOGGER_H
#define LAB6_NPC_LOGGER_H

#include "console_logger.h"
#include "file_logger.h"
#include "../observer/interface/IObserver.h"

namespace lab6 {

class NPCLogger : public IObserver {
private:
  FileLogger file_logger;
  ConsoleLogger console_logger;

public:
  explicit NPCLogger(const std::string& file_name);
  void update(const std::string& name, NPCStatus status) override;
  void kill(const std::string& killer, const std::string& victim) override;
  void create(const std::string& name, NPCType type) override;

  void system_log(LOGType type, const std::string& context);

  virtual ~NPCLogger() = default;
};

}

#endif //LAB6_NPC_LOGGER_H
