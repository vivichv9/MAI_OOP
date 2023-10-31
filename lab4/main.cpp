#include <iostream>

#include "containers/Vector.hpp"
#include "containers/Vector.cpp"
#include "include/Octagon.hpp"
#include "src/Triangle.cpp"
#include "src/Square.cpp"
#include "include/Square.hpp"
#include "include/Triangle.hpp"
#include "include/functions.hpp"
#include "src/functions.cpp"

using point = Point<double>;
using triangle = Triangle<double>;
using square = Square<double>;
using octagon = Octagon<double>;

int main() {
  std::shared_ptr<triangle> t1 = std::make_shared<triangle>(point(1, 1), point(6, 1 + std::sqrt(3) * 5), point(11, 1));
  std::shared_ptr<triangle> t0 = std::make_shared<triangle>(point(0, 0), point(5, std::sqrt(3) * 5), point(10, 0));
  std::shared_ptr<square> s0 = std::make_shared<square>(point(1, 1), point(1, 3), point(3, 3), point(3, 1)); 
  std::shared_ptr<square> s1 = std::make_shared<square>(point(3, 3), point(3, 5), point(5, 5), point(5, 3));
  
  Vector<std::shared_ptr<Figure<double>>> v = {t1, t0, s0, s1};
  print_all_areas(v);
  print_all_centres(v);
  double all_area = calculate_all_area(v);
  std::cout << "Sum of areas: " << all_area << std::endl;
}