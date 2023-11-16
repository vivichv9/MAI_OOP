#include <gtest/gtest.h>

#include "allocator.h"
#include "../src/allocator.cpp"
#include <string>

struct A {
  ~A() {
    std::cout << "DESTROYED";
  }
};

TEST(constructor_test, test_primitive) {
  mystd::allocator<int, 100> a; // TESTED

  EXPECT_EQ(a.get_capacity(), 100);
  EXPECT_EQ(a.get_index(), 0);
}

TEST(constructor_test, test_non_primitive) {
  mystd::allocator<std::string, 100> a; // TESTED

  EXPECT_EQ(a.get_capacity(), 100);
  EXPECT_EQ(a.get_index(), 0);
}

TEST(copy_constructor_test, test_primitive) {
  mystd::allocator<int, 100> a; 
  mystd::allocator<int, 100> b = a; // TESTED

  EXPECT_EQ(b.get_capacity(), a.get_capacity());
  EXPECT_EQ(b.get_index(), a.get_index());
}

TEST(copy_constructor_test, test_non_primitive) {
  mystd::allocator<std::string, 100> a; 
  mystd::allocator<std::string, 100> b = a; // TESTED

  EXPECT_EQ(b.get_capacity(), a.get_capacity());
  EXPECT_EQ(b.get_index(), a.get_index());
}

TEST(allocate_test, primitive_allocate_on_empty_vector) {
  mystd::allocator<int, 100> a;
  int* ptr = a.allocate(3); // TESTED

  EXPECT_EQ(ptr, &(a.get_data()[0]));
  EXPECT_EQ(a.get_index(), 3);
}

TEST(allocate_test, primitive_allocate_on_non_empty_vector) {
  mystd::allocator<int, 100> a;
  [[maybe_unused]] int* non_use_ptr = a.allocate(50);

  int* ptr = a.allocate(3); // TESTED

  EXPECT_EQ(ptr, &(a.get_data()[50]));
  EXPECT_EQ(a.get_index(), 53);
}

TEST(allocate_test, non_primitive_allocate_on_non_empty_vector) {
  mystd::allocator<std::string, 100> a;
  [[maybe_unused]] std::string* non_use_ptr = a.allocate(50);

  std::string* ptr = a.allocate(3); // TESTED

  EXPECT_EQ(ptr, &(a.get_data()[50]));
  EXPECT_EQ(a.get_index(), 53);
}

TEST(allocate_test, non_primitive_allocate_on_empty_vector) {
  mystd::allocator<std::string, 100> a;
  std::string* ptr = a.allocate(3); // TESTED

  EXPECT_EQ(ptr, &(a.get_data()[0]));
  EXPECT_EQ(a.get_index(), 3);
}

TEST(allocate_test, overflow_allocate) {
  mystd::allocator<std::string, 100> a;
  EXPECT_THROW(a.allocate(1000), std::runtime_error); // TESTED
}

TEST(construct_test, construct_primitive) {
  mystd::allocator<int, 100> a;
  int* ptr = a.allocate(1);

  a.construct(ptr, 100); // TESTED
  EXPECT_EQ(*ptr, int{100});
}

TEST(construct_test, construct_non_primitive) {
  mystd::allocator<std::string, 100> a;
  std::string* ptr = a.allocate(1);

  a.construct(ptr, "qwerty"); // TESTED
  EXPECT_EQ(*ptr, std::string{"qwerty"});
}

TEST(deallocate_test, deallocate) {
  mystd::allocator<std::string, 100> a;
  std::string* ptr = a.allocate(10);

  size_t cap = a.get_capacity();
  size_t index = a.get_index();

  a.deallocate(ptr, 10); // TESTED
  
  EXPECT_EQ(cap, a.get_capacity());
  EXPECT_EQ(index, a.get_index());
}

TEST(destroy_test, destroy) {
  mystd::allocator<A, 1> a;
  A* ptr = a.allocate(1);

  a.construct(ptr);

  testing::internal::CaptureStdout();
  a.destroy(ptr); // TESTED
  std::string output = testing::internal::GetCapturedStdout();
  EXPECT_EQ(output, "DESTROYED");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}