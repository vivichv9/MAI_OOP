#include <string>

#include "include/Six.hpp"

int main() {
  Six a{100};
  Six b{200};
  Six f{0};

  Six c = std::move(a);

  std::cout << c << ' ' << a << std::endl;
  std::cout << f << std::endl;

  return 0;
}