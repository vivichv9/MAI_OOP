#include <gtest/gtest.h>

#include "list.h"
#include "../src/list.cpp"
#include <string>

TEST(copy_constructor_test, test) {
  mystd::list<std::string> lst;
  lst.push_front("helmet");

  mystd::list<std::string> lst1 = lst;

  EXPECT_TRUE(lst == lst1);
}

TEST(move_constructor_test, test) {
  mystd::list<std::string> lst;
  lst.push_front("helmet");

  mystd::list<std::string> lst1 = std::move(lst);

  EXPECT_EQ(lst.head, lst.block_elem_ptr);
  EXPECT_EQ(lst.size, 0);
}

TEST(copy_assignment_test, test) {
  mystd::list<std::string> lst;
  mystd::list<std::string> lst1;

  lst.push_front("helmet");

  lst1 = lst;

  EXPECT_TRUE(lst == lst1);
}

TEST(move_assignment_test, test) {
  mystd::list<std::string> lst;
  mystd::list<std::string> lst1;

  lst.push_front("helmet");

  lst1 = std::move(lst);

  EXPECT_EQ(lst.head, lst.block_elem_ptr);
  EXPECT_EQ(lst.size, 0);

  lst.push_front("123");
}

TEST(equal_operator_test, true_test) {
  mystd::list<size_t> lst;
  mystd::list<size_t> lst1;

  for (size_t i = 0; i < 10; ++i) {
    lst.push_front(i);
    lst1.push_front(i);
  }

  EXPECT_TRUE(lst == lst1);
}

TEST(equal_operator_test, false_test) {
  mystd::list<size_t> lst;
  mystd::list<size_t> lst1;

  for (size_t i = 0; i < 10; ++i) {
    lst.push_front(i);
    lst1.push_front(1 + i);
  }

  EXPECT_FALSE(lst == lst1);
}

TEST(not_equal_operator_test, true_test) {
  mystd::list<size_t> lst;
  mystd::list<size_t> lst1;

  for (size_t i = 0; i < 10; ++i) {
    lst.push_front(i);
    lst1.push_front(i + 1);
  }

  EXPECT_TRUE(lst != lst1);
}

TEST(not_equal_operator_test, false_test) {
  mystd::list<size_t> lst;
  mystd::list<size_t> lst1;

  for (size_t i = 0; i < 10; ++i) {
    lst.push_front(i);
    lst1.push_front(i);
  }

  EXPECT_FALSE(lst != lst1);
}

TEST(empty_test, true_test) {
  mystd::list<size_t> lst;

  EXPECT_TRUE(lst.empty());
}

TEST(empty_test, false_test) {
  mystd::list<size_t> lst;

  lst.push_front(123);

  EXPECT_FALSE(lst.empty());
}

TEST(max_size_test, test) {
  mystd::list<size_t> lst;

  for (size_t i = 0; i < 10; ++i) {
    lst.push_front(i);
  }

  EXPECT_EQ(lst.max_size(), 10);
}

TEST(front_test, test_empty_list) {
  mystd::list<size_t> lst;

  EXPECT_ANY_THROW(lst.front());
}

TEST(front_test, test_not_empty_list) {
  mystd::list<size_t> lst;

  lst.push_front(123);

  EXPECT_EQ(lst.front(), 123);
}

TEST(clear_test, test_empty) {
  mystd::list<size_t> lst;

  EXPECT_NO_THROW(lst.clear());
  EXPECT_EQ(lst.size, 0);
  EXPECT_EQ(lst.block_elem_ptr, lst.head);
}

TEST(clear_test, test_non_empty) {
  mystd::list<size_t> lst;

  for (size_t i = 0; i < 10; ++i) {
    lst.push_front(i);
  }

  EXPECT_NO_THROW(lst.clear());
  EXPECT_EQ(lst.size, 0);
  EXPECT_EQ(lst.block_elem_ptr, lst.head);
}

TEST(push_front_test, test) {
  mystd::list<size_t> lst;

  for (size_t i = 0; i < 10; ++i) {
    lst.push_front(i);
  }

  EXPECT_EQ(lst.front(), 9);
}

TEST(pop_front_test, test) {
  mystd::list<size_t> lst;

  for (size_t i = 0; i < 10; ++i) {
    lst.push_front(i);
  }

  lst.pop_front();

  EXPECT_EQ(lst.front(), 8);
}

TEST(pop_front_test, empty_list_test) {
  mystd::list<size_t> lst;

  EXPECT_ANY_THROW(lst.pop_front());
}

TEST(begin_test, test) {
  mystd::list<size_t> lst;

  lst.push_front(13);

  mystd::list<size_t>::iterator it = lst.begin();

  EXPECT_TRUE(mystd::list<size_t>::iterator(lst.head) == it);
}

TEST(cbegin_test, test) {
  mystd::list<size_t> lst;
  lst.push_front(13);

  const mystd::list<size_t> lst1 = lst;
  
  mystd::list<size_t>::iterator it = lst1.cbegin();

  EXPECT_TRUE(mystd::list<size_t>::iterator(lst1.head) == it);
}

TEST(end_test, test) {
  mystd::list<size_t> lst;
  lst.push_front(13);
  
  mystd::list<size_t>::iterator it = lst.end();

  EXPECT_TRUE(mystd::list<size_t>::iterator(lst.block_elem_ptr) == it);
}

TEST(cend_test, test) {
  mystd::list<size_t> lst;
  lst.push_front(13);

  const mystd::list<size_t> lst1 = lst;
  
  mystd::list<size_t>::iterator it = lst1.cend();

  EXPECT_TRUE(mystd::list<size_t>::iterator(lst1.block_elem_ptr) == it);
}

TEST(iterator_increment_test, test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");

  mystd::list<std::string>::iterator it = lst.begin();
  EXPECT_EQ(++it, mystd::list<std::string>::iterator(lst.head->next));
}

TEST(const_iterator_increment_test, test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");

  mystd::list<std::string>::iterator it = lst.cbegin();
  ++it;
  EXPECT_EQ(it, mystd::list<std::string>::iterator(lst.head->next));
}

TEST(plus_equal_operator_test, test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.begin();
  it += 3;
  EXPECT_EQ(it, mystd::list<std::string>::iterator(lst.head->next->next->next));
}

TEST(const_plus_equal_operator_test, test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.cbegin();
  it += 3;
  EXPECT_EQ(it, mystd::list<std::string>::iterator(lst.head->next->next->next));
}

TEST(operator_plus_test, test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.begin();
  it = it + 3;
  EXPECT_EQ(it, mystd::list<std::string>::iterator(lst.head->next->next->next));
}

TEST(dereferencing_test, test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.begin();
  it = it + 3;
  EXPECT_EQ(*it, lst.head->next->next->next->obj);
}

TEST(arrow_dereferencing, test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.begin();
  it = it + 3;
  EXPECT_EQ(it->size(), lst.head->next->next->next->obj.size());
}

TEST(iterator_equal_operator, true_test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.begin();
  mystd::list<std::string>::iterator it1 = lst.begin();
  it = it + 3;
  it1 = it1 + 3;
  EXPECT_TRUE(it == it1);
}

TEST(iterator_equal_operator, false_test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.begin();
  mystd::list<std::string>::iterator it1 = lst.begin();
  it = it + 3;
  it1 = it1 + 2;
  EXPECT_FALSE(it == it1);
}

TEST(iterator_not_equal_operator, true_test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.begin();
  mystd::list<std::string>::iterator it1 = lst.begin();
  it = it + 3;
  it1 = it1 + 3;
  EXPECT_FALSE(it != it1);
}

TEST(iterator_not_equal_operator, false_test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.begin();
  mystd::list<std::string>::iterator it1 = lst.begin();
  it = it + 3;
  it1 = it1 + 2;
  EXPECT_TRUE(it != it1);
}

TEST(insert_after_test, test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.begin();
  ++it;
  lst.insert_after("mouse", it);
  mystd::list<std::string>::iterator it1 = lst.begin();
  it1 += 2;
  EXPECT_EQ(*it1, "mouse");
}

TEST(erase_after_test, test) {
  mystd::list<std::string> lst;
  lst.push_front("privet");
  lst.push_front("hello");
  lst.push_front("run");
  lst.push_front("thread");

  mystd::list<std::string>::iterator it = lst.begin();
  ++it;
  lst.erase_after(it);
  mystd::list<std::string>::iterator it1 = lst.begin();
  it1 += 2;
  EXPECT_EQ(*it1, "privet");
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}