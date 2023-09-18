#include "../include/Solution.hpp"

bool correctly_check(int16_t n, int16_t m) {
  if (n <= 0 || m <= 0) {
    return false;
  }

  return true;
}

void chocolate_division(int16_t n, int16_t m) {
  if (correctly_check(n, m)) {
    std::cout << (n - 1) + (m - 1) << '\n';
    return;
  } 

  std::cout << 0 << '\n';
}