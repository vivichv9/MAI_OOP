#include "../../include/figures/Triangle.hpp"

bool Triangle::validate(const Point& p1, const Point& p2, const Point& p3) noexcept {
  double sum_x = 0;
  double sum_y = 0;
  Point centre(sum_x / 3.0, sum_y / 3.0);

  double len1 = Point::line_len(centre, p1);
  double len2 = Point::line_len(centre, p2);
  double len3 = Point::line_len(centre, p3);

  if (len1 == len2 && len2 == len3) {
    return true;
  }

  return false;
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) {
  bool is_triangle = validate(p1, p2, p3);

  if (!is_triangle) {
    throw std::invalid_argument("Invalid points. Can not create triangle!");
  }

  coordinates.reserve(3);
  coordinates.push_back(p1);
  coordinates.push_back(p2);
  coordinates.push_back(p3);
}

std::ostream& operator<<(std::ostream& os, Triangle& rhs) {
  for (size_t i = 0; i < rhs.coordinates.get_size(); ++i) {
    os << rhs.coordinates[i];
  }
  return os;
}

std::istream& operator>>(std::istream& is, Triangle& rhs) {
  is >> rhs.coordinates[0] >> rhs.coordinates[1] >> rhs.coordinates[2];
  return is;
}

Point Triangle::calculate_centre() const {
  double centre_x = 0;
  double centre_y = 0;

  for (size_t i = 0; i < coordinates.get_size(); ++i) {
    centre_x += coordinates[i].get_x();
    centre_y += coordinates[i].get_y();
  }

  return Point(centre_x / 3, centre_y / 3);
}

Triangle::operator double() const {
  double x2x1 = coordinates[1].get_x() - coordinates[0].get_x();
  double y3y1 = coordinates[2].get_y() - coordinates[0].get_y();
  double x3x1 = coordinates[2].get_x() - coordinates[0].get_x();
  double y2y1 = coordinates[1].get_y() - coordinates[0].get_y();

  double square = std::abs(x2x1 * y3y1 - x3x1 * y2y1) * 0.5;

  return square;
}

