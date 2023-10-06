#include <gtest/gtest.h>
#include "../include/Seven.hpp"

//
// TESTING Seven
//

TEST(string_constructor_test, exception_test) {
  ASSERT_THROW(Seven{"199"}, std::invalid_argument);
}

TEST(string_constructor_test, without_exception_test_0) {
  ASSERT_NO_THROW(Seven{"123"});
}

TEST(string_constructor_test, without_exception_test_1) {
  ASSERT_NO_THROW(Seven{"0"});
}

TEST(constructor_test, exception_test_overflow) {
  ASSERT_THROW(Seven{199}, std::invalid_argument);
}

TEST(constructor_test, exception_test_without_0) {
  ASSERT_NO_THROW(Seven{0});
}

TEST(constructor_test, exception_test_without_1) {
  ASSERT_NO_THROW(Seven{13121212121212});
}

TEST(print_test, test1) {
  Seven test{123};
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "123\n");
}

TEST(print_test, test2) {
  Seven test{0};
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "0\n");
}

TEST(comparison_operator_test, zero_true_test) {
  Seven first{0};
  Seven second{0};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, true_return_1) {
  Seven first{12};
  Seven second{12};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, true_return_2) {
  Seven first{555};
  Seven second{555};

  ASSERT_TRUE(first == second);
}

TEST(comparison_operator_test, false_return_1) {
  Seven first{5555};
  Seven second{5554};

  ASSERT_FALSE(first == second);
}

TEST(comparison_operator_test, false_return_2) {
  Seven first{555};
  Seven second{155};

  ASSERT_FALSE(first == second);
}

TEST(false_comparison_operator_test, true_return) {
  Seven first{1};
  Seven second{0};

  ASSERT_TRUE(first != second);
}

TEST(false_comparison_operator_test, false_return) {
  Seven first{1234};
  Seven second{1234};

  ASSERT_FALSE(first != second);
}

TEST(more_operator_test, true_return_1) {
  Seven first{123};
  Seven second{213};

  EXPECT_TRUE(second > first);
}

TEST(more_operator_test, true_return_2) {
  Seven first{12435};
  Seven second{213};

  EXPECT_TRUE(first > second);
}

TEST(more_operator_test, equals_args) {
  Seven first{213};
  Seven second{213};

  EXPECT_FALSE(first > second);
}

TEST(less_operator_test, false_return) {
  Seven first{21123};
  Seven second{231};

  EXPECT_FALSE(first < second);
}

TEST(less_operator_test, true_return) {
  Seven first{213};
  Seven second{231};

  EXPECT_TRUE(first < second);
}

TEST(less_operator_test, equals_args) {
  Seven first{213};
  Seven second{213};

  EXPECT_FALSE(first < second);
}

TEST(operator_preinc_test, test1) {
  Seven test{666};
  ++test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "1000\n");
}

TEST(operator_preinc_test, test2) {
  Seven test{123};
  ++test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "124\n");
}

TEST(operator_postinc_test, test1) {
  Seven test{123};
  test++;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "124\n");
}

TEST(operator_predec_test, test1) {
  Seven test{332};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "331\n");
}

TEST(operator_predec_test, test2) {
  Seven test{1000};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "666\n");
}

TEST(operator_postdec_test, test1) {
  Seven test{123};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "122\n");
}

TEST(operator_postdec_test, test2) {
  Seven test{1000};
  --test;
  testing::internal::CaptureStdout();
  test.print();
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "666\n");
}

TEST(subtraction_test, test1) {
  Seven test1{"1234"};
  Seven test2{1234};
  Seven expected_result{0};
  Seven result{test1 - test2};

  ASSERT_EQ(result, expected_result);
}

TEST(subtraction_test, exception_test) {
  Seven test1{"1234"};
  Seven test2{12345};
  Seven result{"0"};

  ASSERT_THROW(test1 - test2, std::runtime_error);
}

TEST(subtraction_test, test2) {
  Seven test1{"66"};
  Seven test2{33};
  Seven result{33};

  ASSERT_TRUE(test1 - test2 == result);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}