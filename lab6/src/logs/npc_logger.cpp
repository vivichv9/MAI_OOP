#include "npc_logger.h"

using namespace lab6;

void NPCLogger::update(const std::string& name, NPCStatus status) {
  switch (status) {
    case DEAD:
    console_logger.create_log(INFO, "NPC with name: " + name + " already: DEAD");
    file_logger.create_log(INFO, "NPC with name: " + name + " already: DEAD");
  }

}
