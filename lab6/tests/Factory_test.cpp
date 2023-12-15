#include "iostream"
#include <gtest/gtest.h>
#include "factory/NPCFactory.h"
#include "logs/console_logger.h"

using namespace lab6;

TEST(create_npc_test, test_create_squirrel) {
  NPCFactory factory;

  std::function<void(LOGType, const std::string&)> log([](LOGType logType, const std::string& signature) {
    ConsoleLogger logger;
    logger.create_log(logType, signature);
  });

  std::shared_ptr<NPC> npc;
  EXPECT_NO_THROW(npc = factory.create_npc(log, SQUIRREL, "zina", Square(1, 123)));

  EXPECT_FALSE(npc.get() == nullptr);
  EXPECT_TRUE(npc->getType() == SQUIRREL);

}

TEST(create_npc_test, test_create_werewolf) {
  NPCFactory factory;

  std::function<void(LOGType, const std::string&)> log([](LOGType logType, const std::string& signature) {
    ConsoleLogger logger;
    logger.create_log(logType, signature);
  });

  std::shared_ptr<NPC> npc;
  EXPECT_NO_THROW(npc = factory.create_npc(log, WEREWOLF, "sasha", Square(1, 123)));

  EXPECT_FALSE(npc.get() == nullptr);
  EXPECT_TRUE(npc->getType() == WEREWOLF);
}

TEST(create_npc_test, test_create_druid) {
  NPCFactory factory;

  std::function<void(LOGType, const std::string&)> log([](LOGType logType, const std::string& signature) {
    ConsoleLogger logger;
    logger.create_log(logType, signature);
  });

  std::shared_ptr<NPC> npc;
  EXPECT_NO_THROW(npc = factory.create_npc(log, DRUID, "zhoza", Square(1, 123)));

  EXPECT_FALSE(npc.get() == nullptr);
  EXPECT_TRUE(npc->getType() == DRUID);

}

TEST(create_npc_from_file_test, test_werewolf) {
  NPCFactory factory;

  std::function<void(LOGType, const std::string&)> log([](LOGType logType, const std::string& signature) {
    ConsoleLogger logger;
    logger.create_log(logType, signature);
  });

  std::unordered_map<std::string, std::shared_ptr<NPC>> m;

  EXPECT_NO_THROW(
          factory.create_npc_from_file("/home/kirill/Desktop/study/MAI_OOP/lab6/tests/files/werewolf_data.txt", m,
                                       log));
  EXPECT_FALSE(m.empty());
  EXPECT_TRUE(m.begin()->second->getType() == WEREWOLF);
}

TEST(create_npc_from_file_test, test_squirrel) {
  NPCFactory factory;

  std::function<void(LOGType, const std::string&)> log([](LOGType logType, const std::string& signature) {
    ConsoleLogger logger;
    logger.create_log(logType, signature);
  });

  std::unordered_map<std::string, std::shared_ptr<NPC>> m;

  EXPECT_NO_THROW(
          factory.create_npc_from_file("/home/kirill/Desktop/study/MAI_OOP/lab6/tests/files/squirrel_data.txt", m,
                                       log));
  EXPECT_FALSE(m.empty());
  EXPECT_TRUE(m.begin()->second->getType() == SQUIRREL);
}

TEST(create_npc_from_file_test, test_druid) {
  NPCFactory factory;

  std::function<void(LOGType, const std::string&)> log([](LOGType logType, const std::string& signature) {
    ConsoleLogger logger;
    logger.create_log(logType, signature);
  });

  std::unordered_map<std::string, std::shared_ptr<NPC>> m;

  EXPECT_NO_THROW(
          factory.create_npc_from_file("/home/kirill/Desktop/study/MAI_OOP/lab6/tests/files/druid_data.txt", m,
                                       log));
  EXPECT_FALSE(m.empty());
  EXPECT_TRUE(m.begin()->second->getType() == DRUID);
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}