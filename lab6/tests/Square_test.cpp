#include "iostream"
#include "field/square.h"
#include "gtest/gtest.h"

using namespace lab6;

TEST(square_constructor_test, test_const) {
  EXPECT_NO_THROW(Square s(1, 2));
  EXPECT_ANY_THROW(Square s(1000, 2));
  EXPECT_ANY_THROW(Square s(10, 2000));
}

TEST(square_line_len_test, test) {
  Square s1(10, 0);
  Square s2 (30, 0);

  double l = Square::len(s1, s2);
  EXPECT_TRUE(l == 20);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}