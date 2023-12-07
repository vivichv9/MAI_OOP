#include "NPCFactory.h"

using namespace lab6;

std::shared_ptr<NPC> NPCFactory::create_npc(NPCType npc_type,
                                            const std::string& name,
                                            const Square& npc_field,
                                            NPCStatus state) {
  switch (npc_type) {
    case DRUID:
      logger.create(name, npc_type);
      return std::static_pointer_cast<NPC>(std::make_shared<Druid>(name, npc_field, npc_type, state));

    case SQUIRREL:
      logger.create(name, npc_type);
      return std::static_pointer_cast<NPC>(std::make_shared<Squirrel>(name, npc_field, npc_type, state));

    case WEREWOLF:
      logger.create(name, npc_type);
      return std::static_pointer_cast<NPC>(std::make_shared<Werewolf>(name, npc_field, npc_type, state));

    default:
      throw std::invalid_argument("lab6::factory::create_npc, invalid NPCType");
  }
}

NPCFactory::NPCFactory(NPCLogger& logger) : logger(logger) {}

void
NPCFactory::create_npc_from_file(const std::string& file_path, std::unordered_set<std::shared_ptr<NPC>>& npc_table) {
  std::ifstream file(file_path);
  std::string delimiter = ",";

  std::string str;
  while (file >> str) {
    std::vector<std::string> parsed_str;
    size_t pos;
    std::string token;

    while ((pos = str.find(delimiter)) != std::string::npos) {
      token = str.substr(0, pos);
      parsed_str.push_back(token);
      str.erase(0, pos + delimiter.length());
    }

    parsed_str.push_back(str);

    if (parsed_str[0] == "WEREWOLF") {
      try {
        auto ptr = create_npc(WEREWOLF, parsed_str[1], Square(std::stod(parsed_str[2]), std::stod(parsed_str[3])));
        npc_table.insert(ptr);
      } catch (...) {
        logger.system_log(ERROR, "Exception in func NPCFactory::create_npc_from_file WEREWOLF handler");
      }

    } else if (parsed_str[0] == "SQUIRREL") {
      try {
        auto ptr = create_npc(SQUIRREL, parsed_str[1], Square(std::stod(parsed_str[2]), std::stod(parsed_str[3])));
        npc_table.insert(ptr);
      } catch (...) {
        logger.system_log(ERROR, "Exception in func NPCFactory::create_npc_from_file SQUIRREL handler");
      }

    } else if (parsed_str[0] == "DRUID") {
      try {
        auto ptr = create_npc(DRUID, parsed_str[1], Square(std::stod(parsed_str[2]), std::stod(parsed_str[3])));
        npc_table.insert(ptr);
      } catch (...) {
        logger.system_log(ERROR, "Exception in func NPCFactory::create_npc_from_file DRUID handler");
      }

    } else {
      logger.system_log(ERROR, "Undefined NPC type in func NPCFactory::create_npc_from_file");
      continue;
    }
  }
}
