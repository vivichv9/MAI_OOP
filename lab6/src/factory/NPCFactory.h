#ifndef NPC_FACTORY_H_INCLUDED
#define NPC_FACTORY_H_INCLUDED

#include <memory>
#include "enums/npc_type.h"
#include "npc/include/druid.h"
#include "npc/include/squirrel.h"
#include "npc/include/werewolf.h"
#include "npc/include/npc.h"
#include "logs/logger.h"

namespace lab6::factory {

template <typename... Args>
std::shared_ptr<NPC> create_npc(NPCType npc_type, Args... args);
  
} // namespace lab6


#endif // ifndef NPC_FACTORY_H_INCLUDED