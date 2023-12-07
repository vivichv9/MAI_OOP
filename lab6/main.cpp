#include "src/game_manager/game_manager.h"
#include "logs/console_logger.h"
#include "logs/file_logger.h"

int main(int argc, char** argv) {
  auto* console_logger = new lab6::ConsoleLogger();
  auto* file_logger = new lab6::FileLogger("/home/kirill/Desktop/study/MAI_OOP/lab6/logs/log.txt");

  lab6::GameManager gameManager;

  gameManager.add_observer(console_logger);
  gameManager.add_observer(file_logger);

  gameManager.game_controller();

  delete console_logger;
  delete file_logger;
}