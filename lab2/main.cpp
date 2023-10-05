#include "include/Six.hpp"

int main()
{
  Six a{100};
  Six f{0};
  Six s(1243);

  Vector<Six> vec{123, 341, 1234};
  Vector<Six> kuka;
  kuka = vec;

  for (size_t i = 0; i < kuka.get_size(); ++i) {
    std::cout << kuka[i] << std::endl;
  }

  Six c = std::move(a);
  Six g = s;
  f = g;

  std::cout << c << ' ' << a << std::endl;
  std::cout << f << ' ' << g << ' ' << s << std::endl;

  return 0;
}