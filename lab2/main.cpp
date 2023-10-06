#include "include/Seven.hpp"

int main()
{
  Seven a{100};
  Seven f{0};
  Seven s(1243);

  Vector<Seven> vec{123, 341, 1234};
  Vector<Seven> kuka;
  kuka = vec;

  for (size_t i = 0; i < kuka.get_size(); ++i) {
    std::cout << kuka[i] << std::endl;
  }

  Seven c = std::move(a);
  Seven g = s;
  f = g;

  std::cout << c << ' ' << a << std::endl;
  std::cout << f << ' ' << g << ' ' << s << std::endl;

  return 0;
}