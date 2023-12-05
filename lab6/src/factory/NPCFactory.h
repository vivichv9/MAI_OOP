#ifndef NPC_FACTORY_H_INCLUDED
#define NPC_FACTORY_H_INCLUDED

#include <memory>
#include "../enums/npc_type.h"
#include "../npc/include/druid.h"
#include "../npc/include/squirrel.h"
#include "../npc/include/werewolf.h"
#include "../npc/include/npc.h"
#include "../logs/npc_logger.h"

namespace lab6 {

class NPCFactory {
private:
  NPCLogger logger;

public:
  explicit NPCFactory(const std::string& log_file_name);

  std::shared_ptr<NPC> create_npc(NPCType npc_type, const std::string&  name, const Square& npc_field,
                                  NPCStatus state = NPCStatus::LIVE);
};

} // namespace lab6

#endif // ifndef NPC_FACTORY_H_INCLUDED