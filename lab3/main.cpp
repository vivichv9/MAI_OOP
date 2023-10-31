#include <iostream>

#include "include/figures/Triangle.hpp"
#include "include/figures/Square.hpp"
#include "include/figures/Octagon.hpp"
#include "include/containers/Vector.hpp"
#include "include/functions.hpp"
  
int main() {
  Triangle* t0 = new Triangle(Point(0, 0), Point(5, std::sqrt(3) * 5), Point(10, 0));
  Triangle* t1 = new Triangle(Point(1, 1), Point(6, 1 + std::sqrt(3) * 5), Point(11, 1));
  Square* s0 = new Square(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
  Square* s1 = new Square(Point(2, 2), Point(2, 4), Point(4, 4), Point(4, 2));

  Vector<Figure*> v = {t0, t1, s0, s1};

  double square = calculate_all_area(v);
  print_all_areas(v);
  print_all_centres(v);

  std::cout << square << std::endl;
}