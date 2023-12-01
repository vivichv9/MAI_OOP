#include "NPCFactory.h"

using namespace lab6;

template <typename... Args>
std::shared_ptr<NPC> factory::create_npc(NPCType npc_type, Args ...args) {
  switch(npc_type) {
    case DRUID:
      return std::static_pointer_cast<NPC>(std::make_shared<Druid>(args...));

    case SQUIRREL:
      return std::static_pointer_cast<NPC>(std::make_shared<Squirrel>(args...));
    
    case WEREWOLF:
      return std::static_pointer_cast<NPC>(std::make_shared<Werewolf>(args...));

    default:
      throw std::invalid_argument("lab6::factory::create_npc, invalid NPCType");
  }    
}