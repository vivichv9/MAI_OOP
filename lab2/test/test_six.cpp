#include <gtest/gtest.h>
#include "../include/Six.hpp"

//
// TESTING SIX
//

TEST(string_constructor_test, exception_test) {
  ASSERT_THROW(Six{"199"}, std::invalid_argument);
}

TEST(string_constructor_test, without_exception_test_0) {
  ASSERT_NO_THROW(Six{"123"});
}

TEST(string_constructor_test, without_exception_test_1) {
  ASSERT_NO_THROW(Six{"0"});
}

TEST(constructor_test, exception_test_overflow) {
  ASSERT_THROW(Six{199}, std::invalid_argument);
}

TEST(constructor_test, exception_test_without_0) {
  ASSERT_NO_THROW(Six{0});
}

TEST(constructor_test, exception_test_without_1) {
  ASSERT_NO_THROW(Six{13121212121212});
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

TEST(comparison_operator_test, zero_true_test) {
  Six first{0};
  Six second{0};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, true_return_1) {
  Six first{12};
  Six second{12};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, true_return_2) {
  Six first{555};
  Six second{555};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, false_return_1) {
  Six first{5555};
  Six second{5554};

  ASSERT_FALSE(first == second);
}

TEST(comparison_operator_test, false_return_2) {
  Six first{555};
  Six second{155};

  ASSERT_FALSE(first == second);
}

TEST(false_comparison_operator_test, true_return) {
  Six first{1};
  Six second{0};

  ASSERT_TRUE(first != second);
}

TEST(false_comparison_operator_test, false_return) {
  Six first{1234};
  Six second{1234};

  ASSERT_FALSE(first != second);
}

TEST(more_operator_test, true_return_1) {
  Six first{123};
  Six second{213};

  EXPECT_TRUE(second > first);
}

TEST(more_operator_test, true_return_2) {
  Six first{12435};
  Six second{213};

  EXPECT_TRUE(first > second);
}

TEST(more_operator_test, equals_args) {
  Six first{213};
  Six second{213};

  EXPECT_FALSE(first > second);
}

TEST(less_operator_test, false_return) {
  Six first{21123};
  Six second{231};

  EXPECT_FALSE(first < second);
}

TEST(less_operator_test, true_return) {
  Six first{213};
  Six second{231};

  EXPECT_TRUE(first < second);
}

TEST(less_operator_test, equals_args) {
  Six first{213};
  Six second{213};

  EXPECT_FALSE(first < second);
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

TEST(subtraction_test, test1) {
  Six test1{"1234"};
  Six test2{1234};
  Six expected_result{0};
  Six result{test1 - test2};

  ASSERT_EQ(result, expected_result);
}

TEST(subtraction_test, exception_test) {
  Six test1{"1234"};
  Six test2{12345};
  Six result{"0"};

  ASSERT_THROW(test1 - test2, std::runtime_error);
}

TEST(subtraction_test, test2) {
  Six test1{"5324"};
  Six test2{2345};
  Six result{2535};

  ASSERT_TRUE(test1 - test2 == result);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}