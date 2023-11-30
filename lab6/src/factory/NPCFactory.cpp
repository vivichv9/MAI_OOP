#include "NPCFactory.h"

using namespace lab6;

template <typename... Args>
std::shared_ptr<NPC> factory::create_npc(NPCType npc_type, Args... args) {
  switch(npc_type) {
    case NPCType::DRUID:
      // TODO LOG
      return std::make_shared<NPC>(args);
    
    case NPCType::SQUIRREL:
      // TODO LOG
      return std::make_shared<NPC>(args);
    
    case NPCType::WEREWOLF:
      // TODO LOG
      return std::make_shared<NPC>(args);

    default:
      // TODO LOG
      throw std::invalid_argument("lab6::factory::create_npc, invalid NPCType");
  }    
}