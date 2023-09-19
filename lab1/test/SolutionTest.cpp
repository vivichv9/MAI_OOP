#include <gtest/gtest.h>
#include "../include/Solution.hpp"

TEST(correctly_check_test, normal_data) {
  ASSERT_TRUE(correctly_check(1, 1) == true);
}

TEST(correctly_check_test, first_param_null) {
  ASSERT_TRUE(correctly_check(0, 1) == false);
}

TEST(correctly_check_test, second_param_null) {
  ASSERT_TRUE(correctly_check(1, 0) == false);
}

TEST(correctly_check_test, second_param_negative) {
  ASSERT_TRUE(correctly_check(1, -123) == false);
}

TEST(correctly_check_test, first_param_negative) {
  ASSERT_TRUE(correctly_check(-31, 223) == false);
}

TEST(chocolate_division_test, normal_data) {
  testing::internal::CaptureStdout();
  chocolate_division(3, 4);
  std::string out = testing::internal::GetCapturedStdout();
  EXPECT_EQ(out, "5\n");
}

TEST(chocolate_division_test, bad_data) {
  testing::internal::CaptureStdout();
  chocolate_division(-1, 4);
  std::string out = testing::internal::GetCapturedStdout();
  EXPECT_EQ(out, "0\n");
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}