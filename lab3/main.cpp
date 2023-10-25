#include <iostream>

#include "include/figures/Triangle.hpp"
#include "include/figures/Square.hpp"
#include "include/figures/Octagon.hpp"
#include <vector>

int main() {
  std::vector<Figure*> v;
  try {
    Triangle t(Point::make_point(320, 240), Point::make_point(350, 190), Point::make_point(380, 240));

  } catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }
}