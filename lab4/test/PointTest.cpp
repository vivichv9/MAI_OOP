#include <gtest/gtest.h>

#include "../include/Point.hpp"
#include "../src/Point.cpp"

#define INACCURACY 1e-5

TEST(constructor_test, normal) {
  Point<double> test(3, 5);
  EXPECT_EQ(test.get_x(), 3);
  EXPECT_EQ(test.get_y(), 5);
}

TEST(equal_operator_test, true_test) {
  Point<double> test0(3.1, 5.2);
  Point<double> test1(3.1, 5.2);

  EXPECT_TRUE(test0 == test1);
}

TEST(equal_operator_test, false_test) {
  Point<double> test0(3.1, 5.2);
  Point<double> test1(2, 9);

  EXPECT_FALSE(test0 == test1);
}

TEST(line_len_test, normal) {
  Point<double> p1(4, 5);
  Point<double> p2(8, 9);

  double len = Point<double>::line_len(p1, p2);

  EXPECT_TRUE(len - 5.65685 < INACCURACY);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}