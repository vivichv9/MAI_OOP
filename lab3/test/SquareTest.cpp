#include <gtest/gtest.h>

#include "../include/figures/Square.hpp"

#define INACCURACY 1e-5

TEST(constructor_test, valid_data) {
  EXPECT_NO_THROW(Square(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1)));
}

TEST(constructor_test, invalid_data) {
  EXPECT_THROW(Square(Point(1, 1), Point(1, 3), Point(5, 3), Point(5, 1)), std::invalid_argument);
}

TEST(calculate_centre_test, normal) {
  Square test(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  Point centre = test.calculate_centre();
  EXPECT_TRUE(std::abs(centre.get_x() - 2) < INACCURACY);
  EXPECT_TRUE(std::abs(centre.get_y() - 2) < INACCURACY);
}

TEST(operator_double_test, normal) {
  Square test(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  double square = static_cast<double>(test);
  EXPECT_TRUE(std::abs(square - 4) < INACCURACY);
}


int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}