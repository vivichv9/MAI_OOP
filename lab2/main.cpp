#include "include/Six.hpp"
#include "include/Vector.hpp"
#include "include/Dec.hpp"

#include <string>

int main() {
  lab1::Vector<std::string>* vec = new lab1::Vector<std::string>();
  Dec<int> de(4);

  Six s(123);
  Six a(223);
  Six c(0);
  Six v(0);
  Six d{123};
  Six f{231};

  Six b(a + s);

  std::cout << (d == f) << std::endl;
  std::cout << (s < a) << std::endl;
  std::cout << (s > a) << std::endl;
  std::cout << (c == v) << std::endl;
  std::cout << (s != a) << std::endl;

  b.print();
  return 0;
}