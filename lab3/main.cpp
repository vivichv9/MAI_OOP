#include <iostream>

#include "include/figures/Triangle.hpp"
#include "include/figures/Square.hpp"
#include "include/figures/Octagon.hpp"
#include "include/containers/Vector.hpp"
  
int main() {
  Triangle* t0 = new Triangle(Point(0, 0), Point(5, std::sqrt(3) * 5), Point(10, 0));
  Triangle* t1 = new Triangle(Point(1, 1), Point(6, 1 + std::sqrt(3) * 5), Point(11, 1));
  Square* s0 = new Square(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));

  Vector<Figure*> v = {t0, t1, s0};
  double square = 0;

  for (size_t i = 0; i < v.get_size(); ++i) {
    square += static_cast<double>(*v[i]);
  }

  std::cout << square << std::endl;
}