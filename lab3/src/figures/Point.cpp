#include "../../include/figures/Point.hpp"

Point::Point(double x, double y) : x(x), y(y) {}

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

Point Point::make_point(double x, double y) {
  return Point(x, y);
}

double Point::line_len(const Point& p1, const Point& p2) {
  double ox = p2.get_x() - p1.get_x();
  double oy = p2.get_y() - p1.get_y();

  double len = std::sqrt(std::pow(ox, 2) + std::pow(oy, 2));
  return len;
}

std::ostream& operator<<(std::ostream& os, const Point& rhs) {
  os << '[' << rhs.x << ", " << rhs.y << ']';
  return os;
}

std::istream& operator>>(std::istream& is, Point& rhs) {
  is >> rhs.x >> rhs.y;
  return is;
}