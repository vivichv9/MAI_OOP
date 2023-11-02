#include <gtest/gtest.h>

#include "../include/Square.hpp"
#include "../src/Square.cpp"
#include "../src/Point.cpp"
#include "../containers/Vector.cpp"

#define INACCURACY 1e-5

TEST(constructor_test, valid_data) {
  EXPECT_NO_THROW(Square<double>(Point<double>(1, 1), Point<double>(1, 3), Point<double>(3, 3), Point<double>(3, 1)));
}

TEST(constructor_test, invalid_data) {
  EXPECT_THROW(Square<double>(Point<double>(1, 1), Point<double>(1, 3), Point<double>(5, 3), Point<double>(5, 1)), std::invalid_argument);
}

TEST(calculate_centre_test, normal) {
  Square<double> test(Point<double>(1, 1), Point<double>(1, 3), Point<double>(3, 3), Point<double>(3, 1));
  Point<double> centre = test.calculate_centre();
  EXPECT_TRUE(std::abs(centre.get_x() - 2) < INACCURACY);
  EXPECT_TRUE(std::abs(centre.get_y() - 2) < INACCURACY);
}

TEST(operator_double_test, normal) {
  Square<double> test(Point<double>(1, 1), Point<double>(1, 3), Point<double>(3, 3), Point<double>(3, 1));
  double area = static_cast<double>(test);
  EXPECT_TRUE(std::abs(area - 4) < INACCURACY);
}

TEST(compare_operator_test, true_test) {
  Square<double> test(Point<double>(1, 1), Point<double>(1, 3), Point<double>(3, 3), Point<double>(3, 1));
  Square<double> test1(Point<double>(1, 1), Point<double>(1, 3), Point<double>(3, 3), Point<double>(3, 1));

  EXPECT_TRUE(test == test1);
}

TEST(compare_operator_test, false_test) {
  Square<double> test(Point<double>(1, 1), Point<double>(1, 3), Point<double>(3, 3), Point<double>(3, 1));
  Square<double> test1(Point<double>(2, 2), Point<double>(2, 4), Point<double>(4, 4), Point<double>(4, 2));

  EXPECT_FALSE(test == test1);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}