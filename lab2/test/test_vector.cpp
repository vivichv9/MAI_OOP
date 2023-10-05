#include "gtest/gtest.h"
#include "../include/containers/Vector.hpp"
#include "../include/Six.hpp"


TEST(default_constructor_test, construct_test) {
  Vector<Six> vec;
  EXPECT_EQ(vec.get_capacity(), 1);
  EXPECT_EQ(vec.get_size(), 0);
  EXPECT_NO_THROW(vec[0]);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}