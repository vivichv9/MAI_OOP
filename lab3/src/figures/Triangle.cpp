#include "../../include/figures/Triangle.hpp"

bool Triangle::validate(/* TODO */) {
  // TODO
  return true;
}

Triangle::Triangle(const Point& p1, const Point& p2, const Point& p3) {
  validate(/* TODO */);
  coordinates.reserve(3);
  coordinates.push_back(p1);
  coordinates.push_back(p2);
  coordinates.push_back(p3);
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

