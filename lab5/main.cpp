#include <iostream>
#include <map>
#include <allocator.h>
#include "src/allocator.cpp"
#include <list.h>
#include "src/list.cpp"
#include <chrono>

//BEBRA
int main() {
  std::map<int, int, std::less<int>, mystd::allocator<int, 1000>> m;

  for (size_t i = 0; i < 10; ++i) {
    m.insert({i + 10, i});
  }

  for (auto& e : m) {
    std::cout << '{' << e.first << ", " << e.second << "}, ";
  }

  //SLAWA BEBROW AND MORGENSHTERN 
  std::cout << std::endl;
  mystd::list<int, mystd::allocator<int, 1000>> lst;
  mystd::list<int, mystd::allocator<int, 1000>> a;
  a = lst;

  lst.push_front(123);
  a.push_front(228);

  std::cout << a.max_size() << std::endl;
  std::cout << a.front() << std::endl;
  std::cout << lst.max_size() << std::endl;
  std::cout << lst.front() << std::endl;


  auto start = std::chrono::steady_clock::now();
  mystd::list<size_t, mystd::allocator<size_t, 1000000000>> lsta;
  for (size_t i = 0; i < 100000000; ++i) {
    lsta.push_front(i);
  }
  auto end = std::chrono::steady_clock::now();
  auto time = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
  std::cout << time << std::endl;

  return 0;
}