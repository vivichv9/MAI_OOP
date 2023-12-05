#include "src/game_manager/game_manager.h"

int main(int argc, char** argv) {
  lab6::GameManager gameManager("/home/kirill/Desktop/study/MAI_OOP/lab6/logs/log.txt");
  gameManager.game_controller();
}