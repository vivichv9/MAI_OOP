#include <gtest/gtest.h>
#include <memory>
#include "npc.hpp"
#include "druid.hpp"
#include "werewolf.hpp"
#include "squirrel.hpp"

TEST(Constructor_test, Druid_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  EXPECT_NO_THROW(a = std::make_shared<Druid>(x, y));
  EXPECT_EQ(DruidType, a->get_type());
}

TEST(Constructor_test, Werewolf_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  EXPECT_NO_THROW(a = std::make_shared<Werewolf>(x, y));
  EXPECT_EQ(WerewolfType, a->get_type());
}

TEST(Constructor_test, Squirrel_constructor) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  EXPECT_NO_THROW(a = std::make_shared<Squirrel>(x, y));
  EXPECT_EQ(SquirrelType, a->get_type());
}

TEST(Print_test, Druid_print) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Druid>(x, y);
  testing::internal::CaptureStdout();
  a->print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Druid: { x:100, y:100} \n");
}

TEST(Print_test, Werewolf_print) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Werewolf>(x, y);
  testing::internal::CaptureStdout();
  a->print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Werewolf: { x:100, y:100} \n");
}

TEST(Print_test, Squirrel_print) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Squirrel>(x, y);
  testing::internal::CaptureStdout();
  a->print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "Squirrel: { x:100, y:100} \n");
}

TEST(is_alive_test, Squirrel_is_alive_true) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Squirrel>(x, y);
  EXPECT_TRUE(a->is_alive());
}

TEST(is_alive_test, Werewolf_is_alive_true) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Werewolf>(x, y);
  EXPECT_TRUE(a->is_alive());
}

TEST(is_alive_test, Druid_is_alive_true) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Druid>(x, y);
  EXPECT_TRUE(a->is_alive());
}

TEST(must_die_test, Squirrel_must_die) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Squirrel>(x, y);
  a->must_die();
  EXPECT_FALSE(a->is_alive());
}

TEST(must_die_test, Werewolf_must_die) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Werewolf>(x, y);
  a->must_die();
  EXPECT_FALSE(a->is_alive());
}

TEST(must_die_test, Druid_must_die) {
  int x{100};
  int y{100};

  std::shared_ptr<NPC> a;
  a = std::make_shared<Druid>(x, y);
  a->must_die();
  EXPECT_FALSE(a->is_alive());
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}