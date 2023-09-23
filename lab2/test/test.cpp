#include <gtest/gtest.h>
#include "../include/Six.hpp"
#include "../include/Vector.hpp"

TEST(constructor_test, exception_test_overflow) {
  ASSERT_THROW(Six{199}, std::invalid_argument);
}

TEST(constructor_test, exception_test_without_0) {
  ASSERT_NO_THROW(Six{0});
}

TEST(constructor_test, exception_test_without_1) {
  ASSERT_NO_THROW(Six{12345});
}

TEST(print_test, test1) {
  Six test{123};
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "123\n");
}

TEST(print_test, test2) {
  Six test{0};
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "0\n");
}

TEST(comparison_operator_test, zero_test) {
  Six first{0};
  Six second{0};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, normal_test_1) {
  Six first{12};
  Six second{12};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, normal_test_2) {
  Six first{555};
  Six second{555};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, negative_test_1) {
  Six first{5555};
  Six second{5554};

  ASSERT_FALSE(first == second);
}

TEST(comparison_operator_test, negative_test_2) {
  Six first{555};
  Six second{155};

  ASSERT_FALSE(first == second);
}

TEST(false_comparison_operator_test, normal_data_1) {
  Six first{1};
  Six second{0};

  ASSERT_FALSE(first == second);
}

TEST(false_comparison_operator_test, normal_data_2) {
  Six first{1234};
  Six second{12};

  ASSERT_FALSE(first == second);
}

TEST(more_operator_test, normal_data_1) {
  Six first{123};
  Six second{213};

  EXPECT_TRUE(second > first);
}

TEST(more_operator_test, normal_data_2) {
  Six first{12435};
  Six second{213};

  EXPECT_TRUE(second > first);
}

TEST(operator_preinc_test, test1) {
  Six test{555};
  ++test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "1000\n");
}

TEST(operator_preinc_test, test2) {
  Six test{123};
  ++test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "124\n");
}

TEST(operator_postinc_test, test1) {
  Six test{123};
  test++;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "124\n");
}

TEST(operator_predec_test, test1) {
  Six test{332};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "331\n");
}

TEST(operator_predec_test, test2) {
  Six test{1000};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "555\n");
}

TEST(operator_postdec_test, test1) {
  Six test{123};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "122\n");
}

TEST(operator_postdec_test, test2) {
  Six test{1000};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "555\n");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}