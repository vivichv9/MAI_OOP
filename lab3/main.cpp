#include <iostream>

#include "include/figures/Triangle.hpp"
#include "include/figures/Square.hpp"
#include "include/figures/Octagon.hpp"
#include "include/containers/Vector.hpp"
  
int main() {
  try {
    Triangle t(Point::make_point(0, 0), Point::make_point(5, std::sqrt(3) * 5), Point::make_point(10, 0));
    std::cout << t.calculate_centre() << std::endl;
    std::cout << (double) t << std::endl;

    Square s(Point(1, 1), Point(1, 3), Point(3, 3), Point(3, 1));
    std::cout << s.calculate_centre() << std::endl;
    std::cout << (double) s << std::endl;

    Point p1(10, 10);
    Point p2(p1.get_x() - (1 + std::sqrt(2)), p1.get_y() + 1);
    Point p3(p2.get_x() - 1, p2.get_y() + 1 + std::sqrt(2));
    Point p4(p3.get_x() + 1, p3.get_y() + (1 + std::sqrt(2)));
    Point p5(p4.get_x() + 1 + std::sqrt(2), p4.get_y() + 1);
    Point p6(p5.get_x() + 1 + std::sqrt(2), p5.get_y() - 1);
    Point p7(p6.get_x() + 1, p6.get_y() - (1 + std::sqrt(2)));
    Point p8(p7.get_x() - 1, p7.get_y() - (1 + std::sqrt(2)));

    Octagon o(p1, p2, p3, p4, p5, p6, p7, p8);
    std::cout << o.calculate_centre() << std::endl;
    std::cout << (double) o << std::endl;
  } catch (std::invalid_argument& e) {
    std::cout << e.what() << std::endl;
  }
}