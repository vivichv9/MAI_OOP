#include <gtest/gtest.h>
#include "../include/Solution.hpp"
#include "../src/Solution.cpp"

TEST(CorrCheckTest, basic_test_set) {
  ASSERT_TRUE(correctly_check(1, 1) == true);
  ASSERT_TRUE(correctly_check(0, 1) == false);
  ASSERT_TRUE(correctly_check(1, 0) == false);
  ASSERT_TRUE(correctly_check(1, -123) == false);
  ASSERT_TRUE(correctly_check(-31, 223) == false);
  ASSERT_TRUE(correctly_check(41, 112) == true);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}