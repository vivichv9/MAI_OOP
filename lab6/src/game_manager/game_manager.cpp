#include "game_manager.h"

using namespace lab6;

GameManager::GameManager(const std::string& log_file_name) : logger(log_file_name), factory(logger) {}

void GameManager::game_controller() {
  factory.create_npc_from_file("/home/kirill/Desktop/study/MAI_OOP/lab6/data/npc.txt", npc_table);

  attack_cycle(100);
}

void GameManager::attack_cycle(double attack_range) {
  Visitor v;
  for (auto& i: npc_table) {
    for (auto& j: npc_table) {
      if (i != j) {
        i->attack(&v, j.get(), attack_range, logger);
      }
    }
  }
}
