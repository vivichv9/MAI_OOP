#include "include/Solution.hpp"

int main() {
  int32_t n;
  int32_t m;

  std::cout << "Please enter n and m \n";
  std::cin >> n >> m;

  int32_t res = chocolate_division(n, m);
  std::cout << "Result: " << res << '\n';
  
  return 0;
}