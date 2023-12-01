#ifndef LAB6_NPC_LOGGER_H
#define LAB6_NPC_LOGGER_H

#include "console_logger.h"
#include "file_logger.h"
#include "observer/interface/IObserver.h"

namespace lab6 {

class NPCLogger : public IObserver {
private:
  FileLogger file_logger;
  ConsoleLogger console_logger;

public:
  void update(lab6::NPCStatus status) override;
};

}

#endif //LAB6_NPC_LOGGER_H
