#include <gtest/gtest.h>
#include "../include/Solution.hpp"

TEST(correctly_check_test, normal_data) {
  ASSERT_TRUE(correctly_check(1, 1));
}

TEST(correctly_check_test, first_param_null) {
  ASSERT_FALSE(correctly_check(0, 1));
}

TEST(correctly_check_test, second_param_null) {
  ASSERT_FALSE(correctly_check(1, 0));
}

TEST(correctly_check_test, second_param_negative) {
  ASSERT_FALSE(correctly_check(1, -123));
}

TEST(correctly_check_test, first_param_negative) {
  ASSERT_FALSE(correctly_check(-31, 223));
}

TEST(correctly_check_test, params_negative) {
  ASSERT_FALSE(correctly_check(-31, -99));
}

TEST(correctly_check_test, params_null) {
  ASSERT_FALSE(correctly_check(0, 0));
}

TEST(chocolate_division_test, null_params) {
  int32_t res = chocolate_division(0, 0);
  EXPECT_EQ(res, 0);
}

TEST(chocolate_division_test, bad_params) {
  int32_t res = chocolate_division(-13, -54);
  EXPECT_EQ(res, 0);
}

TEST(chocolate_division_test, bad_second_param) {
  int32_t res = chocolate_division(8, -2);
  EXPECT_EQ(res, 0);
}

TEST(chocolate_division_test, normal_data) {
  int32_t res = chocolate_division(3, 4);
  EXPECT_EQ(res, 5);
}

TEST(chocolate_division_test, bad_first_param) {
  int32_t res = chocolate_division(-1, 4);
  EXPECT_EQ(res, 0);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}