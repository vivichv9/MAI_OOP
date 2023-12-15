#include "iostream"
#include "gtest/gtest.h"
#include "logs/console_logger.h"
#include "logs/file_logger.h"

using namespace lab6;

TEST(console_logger_test, info_test) {
  ConsoleLogger log;
  testing::internal::CaptureStdout();
  log.create_log(INFO, "hello");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "[INFO]: hello\n");
}

TEST(console_logger_test, warning_test) {
  ConsoleLogger log;
  testing::internal::CaptureStdout();
  log.create_log(WARNING, "hello");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "[WARNING]: hello\n");
}

TEST(console_logger_test, error_test) {
  ConsoleLogger log;
  testing::internal::CaptureStdout();
  log.create_log(ERROR, "hello");
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "[ERROR]: hello\n");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}