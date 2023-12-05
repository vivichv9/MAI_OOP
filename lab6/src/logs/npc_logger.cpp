#include "npc_logger.h"

using namespace lab6;

void NPCLogger::update(const std::string& name, NPCStatus status) {
  switch (status) {
    case DEAD:
      console_logger.create_log(INFO, "NPC with name " + name + " already: DEAD");
      file_logger.create_log(INFO, "NPC with name " + name + " already: DEAD");
      return;

    case LIVE:
      console_logger.create_log(INFO, "NPC with name " + name + " already: LIVE");
      file_logger.create_log(INFO, "NPC with name " + name + " already: LIVE");

    default:
      console_logger.create_log(WARNING, "Undefined NPC type! in func NPCLogger::update");
      file_logger.create_log(WARNING, "Undefined NPC Type! in func NPCLogger::update");
  }
}

NPCLogger::NPCLogger(const std::string& file_name) : file_logger(file_name) {}

void NPCLogger::create(const std::string &name, NPCType type) {
  switch (type) {
    case SQUIRREL:
      console_logger.create_log(INFO, "NPC Squirrel with name " + name + " created");
      file_logger.create_log(INFO, "NPC Squirrel with name " + name + " created");
      break;

    case WEREWOLF:
      console_logger.create_log(INFO, "NPC Werewolf with name " + name + " created");
      file_logger.create_log(INFO, "NPC Werewolf with name " + name + " created");
      break;

    case DRUID:
      console_logger.create_log(INFO, "NPC Squirrel with name " + name + " created");
      file_logger.create_log(INFO, "NPC Squirrel with name " + name + " created");
      break;

    default:
      console_logger.create_log(WARNING, "Undefined NPC type! in func NPCLogger::create");
      file_logger.create_log(WARNING, "Undefined NPC Type! in func NPCLogger::create");
  }
}

void NPCLogger::system_log(LOGType type, const std::string &context) {
  console_logger.create_log(type, context);
  file_logger.create_log(type, context);
}

void NPCLogger::kill(const std::string& killer, const std::string& victim) {
  console_logger.create_log(INFO, "MURDER: " + victim + " killed by " + killer);
  file_logger.create_log(INFO, "MURDER: " + victim + " killed by " + killer);
}
