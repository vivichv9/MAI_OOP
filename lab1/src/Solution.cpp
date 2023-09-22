#include "../include/Solution.hpp"

bool correctly_check(int32_t n, int32_t m) {
  if (n <= 0 || m <= 0) {
    return false;
  }

  return true;
}

int32_t chocolate_division(int32_t n, int32_t m) {
  if (correctly_check(n, m)) {
    return (n - 1) + (m - 1);
  } 

  return 0;
}