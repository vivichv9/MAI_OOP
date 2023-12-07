#ifndef NPC_FACTORY_H_INCLUDED
#define NPC_FACTORY_H_INCLUDED

#include <memory>
#include "fstream"
#include "unordered_set"
#include "enums/npc_type.h"
#include "npc/include/druid.h"
#include "npc/include/squirrel.h"
#include "npc/include/werewolf.h"
#include "npc/include/npc.h"

namespace lab6 {

class NPCFactory {
public:
  NPCFactory() = default;

  std::shared_ptr<NPC> create_npc(std::function<void(LOGType, const std::string&)>& log,
                                  NPCType npc_type, const std::string& name, const Square& npc_field,
                                  NPCStatus state = NPCStatus::LIVE);

  void create_npc_from_file(const std::string& file_path, std::unordered_set<std::shared_ptr<NPC>>& npc_table,
                            std::function<void(LOGType, const std::string&)>& log);
};

} // namespace lab6

#endif // ifndef NPC_FACTORY_H_INCLUDED