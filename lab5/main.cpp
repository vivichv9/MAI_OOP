#include <iostream>
#include "list.h"
#include "src/list.cpp"

int main() {
  mystd::list<int> lst;
  mystd::list<int> a;
  a = lst;
  lst.push_front(123);
  std::cout << lst.max_size() << std::endl;
  std::cout << lst.front() << std::endl;
  return 0;
}