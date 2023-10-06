#include "gtest/gtest.h"
#include "../include/containers/Vector.hpp"
#include "../include/Seven.hpp"


TEST(constructor_test, default_constructor_test) {
  Vector<Seven> vec; // TESTED

  EXPECT_EQ(vec.get_capacity(), 1);
  EXPECT_EQ(vec.get_size(), 0);
  EXPECT_NO_THROW(vec[0]);
}

TEST(constructor_test, capacity_constructor_test) {
  Vector<Seven> vec(100); // TESTED

  EXPECT_EQ(vec.get_capacity(), 100);
  EXPECT_EQ(vec.get_size(), 0);
}

TEST(constructor_test, initializer_constructor_test) {
  Vector<Seven> vec{123, 123, 123, 23, 123, 2331}; // TESTED

  EXPECT_EQ(vec.get_capacity(), 6);
  EXPECT_EQ(vec.get_size(), 6);
}

TEST(constructor_test, copy_constructor_test) {
  Vector<Seven> vec{1234, 12345, 4124};
  Vector<Seven> vec1 = vec; // TESTED

  EXPECT_EQ(vec1.get_size(), 3);
  EXPECT_EQ(vec1.get_capacity(), 3);

  for (size_t i = 0; i < vec.get_size(); ++i) {
    EXPECT_EQ(vec1[i], vec[i]);
  }
}

TEST(constructor_test, move_constructor_test) {
  Vector<Seven> vec{1234, 12345, 4124, 12345123};

  Vector<Seven> vec1 = std::move(vec); // TESTED

  EXPECT_EQ(vec1.get_size(), 4);
  EXPECT_EQ(vec1.get_capacity(), 4);
  EXPECT_EQ(vec1[0], Seven{1234});
  EXPECT_EQ(vec1[1], Seven{12345});
  EXPECT_EQ(vec1[2], Seven{4124});
  EXPECT_EQ(vec1[3], Seven{12345123});

  EXPECT_EQ(vec.get_size(), 0);
  EXPECT_EQ(vec.get_capacity(), 0);
}

TEST(assignment_operator_test, copy_assignment) {
  Vector<Seven> vec{1234, 12345, 4124, 12345123};
  Vector<Seven> vec1;

  vec1 = vec; // TESTED

  EXPECT_EQ(vec1.get_size(), 4);
  EXPECT_EQ(vec1.get_capacity(), 4);

  for (size_t i = 0; i < vec.get_size(); ++i) {
    EXPECT_EQ(vec1[i], vec[i]);
  }

  EXPECT_TRUE(vec == vec1);
}

TEST(assignment_operator_test, move_assignment) {
  Vector<Seven> vec{1234, 12345};
  Vector<Seven> vec1;

  vec1 = std::move(vec); // TESTED

  EXPECT_EQ(vec1.get_size(), 2);
  EXPECT_EQ(vec1.get_capacity(), 2);
  EXPECT_EQ(vec1[0], Seven{1234});
  EXPECT_EQ(vec1[1], Seven{12345});

  EXPECT_EQ(vec.get_size(), 0);
  EXPECT_EQ(vec.get_capacity(), 0);
}

TEST(get_size_test, empty_vector) {
  Vector<Seven> v;
  size_t size = v.get_size(); // TESTED

  EXPECT_EQ(size, 0);
}

TEST(get_size_test, non_empty_vector) {
  Vector<Seven> v{123, 412, 12451, 12345, 123, 1234, 134, 1234, 412, 14};
  size_t size = v.get_size(); // TESTED

  EXPECT_EQ(size, 10);
}

TEST(get_capacity_test, empty_vector) {
  Vector<Seven> v;
  size_t capacity = v.get_capacity(); // TESTED

  EXPECT_EQ(capacity, 1);
}

TEST(get_capacity_test, non_empty_vector) {
  Vector<Seven> v{123, 412, 12451, 12345, 123, 1234, 134, 1234, 412, 14};
  size_t capacity = v.get_capacity(); // TESTED

  EXPECT_EQ(capacity, 10);
}

TEST(empty_test, empty_vector) {
  Vector<Seven> v;
  bool is_empty = v.empty(); // TESTED

  ASSERT_TRUE(is_empty);
}

TEST(empty_test, non_empty_vector) {
  Vector<Seven> v{123, 124, 1245};
  bool is_empty = v.empty(); // TESTED
  
  ASSERT_FALSE(is_empty);
}

TEST(empty_test, const_empty_vector) {
  const Vector<Seven> v;
  bool is_empty = v.empty(); // TESTED

  ASSERT_TRUE(is_empty);
}

TEST(empty_test, const_non_empty_vector) {
  const Vector<Seven> v{123, 124, 1245};
  bool is_empty = v.empty(); // TESTED
  
  ASSERT_FALSE(is_empty);
}

TEST(equal_operator_test, equal_vectors) {
  Vector<Seven> v{123, 124, 1245};
  Vector<Seven> v1 = v;
  
  bool is_equal = v1 == v; // TESTED
  EXPECT_TRUE(is_equal);
}

TEST(equal_operator_test, non_equal_vectors_with_non_equal_size) {
  Vector<Seven> v{123, 124, 1245};
  Vector<Seven> v1{1234, 123, 12345, 1234, 1234};
  
  bool is_equal = v1 == v; // TESTED
  EXPECT_FALSE(is_equal);
}

TEST(equal_operator_test, non_equal_vectors_with_equal_size) {
  Vector<Seven> v{123, 124, 1245};
  Vector<Seven> v1{1234, 123, 12345};
  
  bool is_equal = v1 == v; // TESTED
  EXPECT_FALSE(is_equal);
}

TEST(non_equal_operator_test, non_equal_vectors_with_equal_size) {
  Vector<Seven> v{123, 124, 1245};
  Vector<Seven> v1{1234, 123, 12345};
  
  bool is_equal = v1 != v; // TESTED
  EXPECT_TRUE(is_equal);
}

TEST(non_equal_operator_test, non_equal_vectors_with_non_equal_size) {
  Vector<Seven> v{123, 124, 1245};
  Vector<Seven> v1{1234, 123, 12345, 1234, 1234};
  
  bool is_equal = v1 != v; // TESTED
  EXPECT_TRUE(is_equal);
}

TEST(non_equal_operator_test, equal_vectors) {
  Vector<Seven> v{123, 124, 1245};
  Vector<Seven> v1 = v;
  
  bool is_equal = v1 != v; // TESTED
  EXPECT_FALSE(is_equal);
}

TEST(resize_test, resize_empty_vector) {
  Vector<Seven> v;
  size_t size = 10;
  v.resize(size, Seven{1}); // TESTED

  EXPECT_EQ(v.get_capacity(), size);
  EXPECT_EQ(v.get_size(), size);

  for (size_t i = 0; i < v.get_size(); ++i) {
    EXPECT_EQ(v[i], Seven{1});
  }
}

TEST(resize_test, non_empty_vector) {
  Vector<Seven> v{123, 1234, 1234123, 14212451};
  size_t old_size = v.get_size();
  size_t size = 15;

  v.resize(size, Seven{1}); // TESTED

  EXPECT_EQ(v.get_size(), 15);
  EXPECT_EQ(v.get_capacity(), 15);

  EXPECT_EQ(v[0], Seven{123});
  EXPECT_EQ(v[1], Seven{1234});
  EXPECT_EQ(v[2], Seven{1234123});
  EXPECT_EQ(v[3], Seven{14212451});

  for (size_t i = old_size; i < v.get_size(); ++i) {
    EXPECT_EQ(v[i], Seven{1});
  }
}

TEST(reserve_test, empty_vector) {
  Vector<Seven> v;
  size_t capacity = 100;

  v.reserve(capacity); // TESTED

  EXPECT_EQ(v.get_capacity(), capacity);
}

TEST(reserve_test, old_capacity_more_new_capacity) {
  Vector<Seven> v(123);
  size_t capacity = 100;

  v.reserve(capacity); // TESTED

  EXPECT_EQ(v.get_capacity(), 123);
}

TEST(pop_back_test, non_empty_vector) {
  Vector<Seven> v{123, 145, 12345};
  size_t size = v.get_size();

  v.pop_back(); // TESTED

  EXPECT_EQ(size - 1, v.get_size());
  EXPECT_EQ(v[v.get_size() - 1], Seven{145});
}

TEST(push_back_test, non_empty_vector) {
  Vector<Seven> v{123, 145, 12345};
  size_t size = v.get_size();

  v.push_back(Seven{1234}); // TESTED

  EXPECT_EQ(v.get_size(), size + 1);
  EXPECT_EQ(v[v.get_size() - 1], Seven{1234});
}

TEST(clear_test, empty_vector) {
  Vector<Seven> v;
  
  EXPECT_NO_THROW(v.clear()); // TESTED

  EXPECT_EQ(v.get_size(), 0);
  EXPECT_EQ(v.get_capacity(), 1);
}

TEST(clear_test, non_empty_vector) {
  Vector<Seven> v{14123, 123124, 1231, 1233};

  EXPECT_NO_THROW(v.clear()); // TESTED

  EXPECT_EQ(v.get_capacity(), 4);
  EXPECT_EQ(v.get_size(), 0);
  EXPECT_THROW(v.at(1), std::range_error);
}

TEST(emplace_back_test, non_empty_vector) {
  Vector<Seven> v{14123, 123124, 1231, 1233};
  size_t size = v.get_size();
  size_t capacity = v.get_capacity();

  v.emplace_back("12312313123132312312321313123132213"); // TESTED

  EXPECT_EQ(capacity * 2, v.get_capacity());
  EXPECT_EQ(size + 1, v.get_size());
  EXPECT_EQ(v[v.get_size() - 1], Seven{"12312313123132312312321313123132213"});
}

TEST(get_element_operator_test, non_empty_vector) {
  Vector<Seven> v{123, 124, 12324123, 123124123};

  Seven el0 = v[0]; // TESTED
  Seven el1 = v[1]; // 
  Seven el2 = v[2]; //  
  Seven el3 = v[3]; //

  EXPECT_EQ(el0, Seven{123});
  EXPECT_EQ(el1, Seven{124});
  EXPECT_EQ(el2, Seven{12324123});
  EXPECT_EQ(el3, Seven{123124123});
}

TEST(at_test, out_of_range_test) {
  Vector<Seven> v{123, 124, 12324123, 123124123};

  EXPECT_THROW(v.at(5), std::range_error);
}

TEST(at_test, normal_test) {
  Vector<Seven> v{123, 124, 12324123, 123124123};

  EXPECT_NO_THROW(v.at(3));
  EXPECT_EQ(v.at(3), Seven{"123124123"});
}

TEST(front_test, normal_test) {
  Vector<Seven> v{123, 124, 12324123, 123124123};

  EXPECT_EQ(v.front(), Seven{"123"});
}
 
int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}