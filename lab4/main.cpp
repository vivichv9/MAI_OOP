#include <iostream>
#include <memory>

#include "Vector.h"
#include "containers/src/Vector.cpp"
#include "Octagon.h"
#include "src/Octagon.cpp"
#include "Square.h"
#include "src/Square.cpp"
#include "src/functions.cpp"
#include <Triangle.h>
#include "src/Triangle.cpp"
#include "functions.h"
#include <Point.h>
#include "src/Point.cpp"

using triangle = Triangle<double>;
using square = Square<double>;
using point = Point<double>;

int main() {
  std::shared_ptr<triangle> t1 = std::make_shared<triangle>(point(1, 1), point(6, 1 + std::sqrt(3) * 5), point(11, 1));
  std::shared_ptr<triangle> t0 = std::make_shared<triangle>(point(0, 0), point(5, std::sqrt(3) * 5), point(10, 0));
  std::shared_ptr<square> s0 = std::make_shared<square>(point(1, 1), point(1, 3), point(3, 3), point(3, 1)); 
  std::shared_ptr<square> s1 = std::make_shared<square>(point(3, 3), point(3, 5), point(5, 5), point(5, 3));
  mystd::Vector<std::shared_ptr<Figure<double>>> v = {t1, t0, s0, s1};
  print_all_areas(v);
  print_all_centres(v);
  double all_area = calculate_all_area(v);
  std::cout << "Sum of areas: " << all_area << std::endl;
}