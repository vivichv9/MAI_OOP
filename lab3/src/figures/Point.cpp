#include "../../include/figures/Point.hpp"

void Point::set_x(double x) noexcept {
  this->x = x;
}

void Point::set_y(double y) noexcept {
  this->y = y;
}

double Point::get_x() const noexcept {
  return x;
}

double Point::get_y() const noexcept {
  return y;
}

static Point Point::make_point(double x, double y) {
  return Point{x, y};
}

friend std::ostream& operator<<(std::ostream& os, const Point& rhs) {
  os << rhs.x << ' ' << rhs.y;
}

friend std::istream& operator>>(std::istream& is, const Point& rhs) {
  is >> rhs.x >> rhs.y;
}