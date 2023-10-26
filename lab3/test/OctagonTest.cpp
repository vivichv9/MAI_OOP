#include <gtest/gtest.h>

#include "../include/figures/Octagon.hpp"

#define INACCURACY 1e-4

TEST(constructor_test, valid_data) {
  Point p1(10, 10);
  Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  EXPECT_NO_THROW(Octagon(p1, p2, p3, p4, p5, p6, p7, p8));
}

TEST(constructor_test, invalid_data) {
  Point p1(10, 10);
  Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point p5(p4.get_x() + 9 + std::sqrt(2), p4.get_y() + 1);
  Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  EXPECT_THROW(Octagon(p1, p2, p3, p4, p5, p6, p7, p8), std::invalid_argument);
}

TEST(calculate_centre_test, normal) {
  Point p1(10, 10);
  Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  Octagon test(p1, p2, p3, p4, p5, p6, p7, p8);

  Point centre = test.calculate_centre();

  EXPECT_TRUE(centre.get_x() - 10 < INACCURACY);
  EXPECT_TRUE(centre.get_y() - 13.4142 < INACCURACY);
}

TEST(operator_double_test, normal) {
  Point p1(10, 10);
  Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  Octagon test(p1, p2, p3, p4, p5, p6, p7, p8);

  double square = static_cast<double>(test);
  EXPECT_TRUE(square - 32.9706 < INACCURACY);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}