#include <gtest/gtest.h>

#include "../include/Octagon.hpp"
#include "../src/Octagon.cpp"
#include "../src/Point.cpp"
#include "../containers/Vector.cpp"

#define INACCURACY 1e-4

TEST(constructor_test, valid_data) {
  Point<double> p1(10, 10);
  Point<double> p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point<double> p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point<double> p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point<double> p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point<double> p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point<double> p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point<double> p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  EXPECT_NO_THROW(Octagon<double>(p1, p2, p3, p4, p5, p6, p7, p8));
}

TEST(constructor_test, invalid_data) {
  Point<double> p1(10, 10);
  Point<double> p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point<double> p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point<double> p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point<double> p5(p4.get_x() + 9 + std::sqrt(2), p4.get_y() + 1);
  Point<double> p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point<double> p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point<double> p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  EXPECT_THROW(Octagon<double>(p1, p2, p3, p4, p5, p6, p7, p8), std::invalid_argument);
}

TEST(calculate_centre_test, normal) {
  Point<double> p1(10, 10);
  Point<double> p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point<double> p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point<double> p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point<double> p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point<double> p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point<double> p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point<double> p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  Octagon<double> test(p1, p2, p3, p4, p5, p6, p7, p8);

  Point<double> centre = test.calculate_centre();

  EXPECT_TRUE(centre.get_x() - 10 < INACCURACY);
  EXPECT_TRUE(centre.get_y() - 13.4142 < INACCURACY);
}

TEST(operator_double_test, normal) {
  Point<double> p1(10, 10);
  Point<double> p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point<double> p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point<double> p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point<double> p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point<double> p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point<double> p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point<double> p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  Octagon<double> test(p1, p2, p3, p4, p5, p6, p7, p8);

  double square = static_cast<double>(test);
  EXPECT_TRUE(square - 32.9706 < INACCURACY);
}

TEST(compare_operator_test, true_test) {
  Point<double> p1(10, 10);
  Point<double> p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point<double> p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point<double> p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point<double> p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point<double> p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point<double> p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point<double> p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  Octagon<double> test(p1, p2, p3, p4, p5, p6, p7, p8);
  Octagon<double> test1(p1, p2, p3, p4, p5, p6, p7, p8);

  EXPECT_TRUE(test == test1);
}

TEST(compare_operator_test, false_test) {
  Point<double> p1(1, 1);
  Point<double> p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
  Point<double> p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
  Point<double> p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
  Point<double> p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
  Point<double> p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
  Point<double> p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
  Point<double> p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

  Point<double> pp1(5, 5);
  Point<double> pp2(pp1.get_x() - (1 + std::sqrt(2)), pp1.get_y() + 1);
  Point<double> pp3(pp2.get_x() - 1, pp2.get_y() + 1 + std::sqrt(2));
  Point<double> pp4(pp3.get_x() + 1, pp3.get_y() + (1 + std::sqrt(2)));
  Point<double> pp5(pp4.get_x() + 1 + std::sqrt(2), pp4.get_y() + 1);
  Point<double> pp6(pp5.get_x() + 1 + std::sqrt(2), pp5.get_y() - 1);
  Point<double> pp7(pp6.get_x() + 1, pp6.get_y() - (1 + std::sqrt(2)));
  Point<double> pp8(pp7.get_x() - 1, pp7.get_y() - (1 + std::sqrt(2)));

  Octagon<double> test(p1, p2, p3, p4, p5, p6, p7, p8);
  Octagon<double> test1(pp1, pp2, pp3, pp4, pp5, pp6, pp7, pp8);

  EXPECT_FALSE(test == test1);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}