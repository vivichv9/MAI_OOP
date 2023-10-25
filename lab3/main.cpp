#include <iostream>

#include "include/figures/Triangle.hpp"
#include "include/figures/Square.hpp"
#include "include/figures/Octagon.hpp"
#include <vector>
  
int main() {
  try {
    Triangle t(Point::make_point(0, 0), Point::make_point(5, std::sqrt(3) * 5), Point::make_point(10, 0));
    std::cout << t.calculate_centre() << std::endl;
    std::cout << (double) t << std::endl;
  } catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }
}