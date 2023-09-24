#include <string>

#include "include/Six.hpp"

int main() {
  Six s{123};
  Six a{223};

  Six b{a + s};

  std::cout << b << std::endl;

  return 0;
}