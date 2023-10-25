#include "../../include/figures/Triangle.hpp"

bool Triangle::validate(const Point& p1, const Point& p2, const Point& p3) noexcept {
  // TODO
  return true;
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) {
  bool flag = validate(p1, p2, p3);

  if (!flag) {
    throw std::invalid_argument("Invalid points. Can not create triangle!");
  }

  coordinates.reserve(3);
  coordinates.push_back(p1);
  coordinates.push_back(p2);
  coordinates.push_back(p3);
}

friend std::ostream& operator<<(std::ostream& os, const Triangle& rhs) {
  for (size_t i = 0; i < rhs.coordinates.get_size(); ++i) {
    os << rhs.coordinates[i];
  }
}

Point Triangle::calculate_centre() const {
  double centre_x = 0;
  double centre_y = 0;

  for (size_t i = 0; i < coordinates.get_size(); ++i) {
    centre_x += coordinates[i].x;
    centre_y += coordinates[i].y;
  }

  return Point{centre_x / 3, centre_y / 3};
}

Triangle::operator double() const {
  // TODO
  return 1;
}

