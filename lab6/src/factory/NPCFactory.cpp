#include "NPCFactory.h"

using namespace lab6;

std::shared_ptr<NPC> NPCFactory::create_npc(NPCType npc_type,
                                                     const std::string& name,
                                                     const Square& npc_field,
                                                     NPCStatus state) {
  switch(npc_type) {
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


NPCFactory::NPCFactory(const std::string &log_file_name) : logger(log_file_name) {}
