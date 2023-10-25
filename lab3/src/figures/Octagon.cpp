#include "../../include/figures/Octagon.hpp"

bool Octagon::validate(    
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6,
    const Point& p7,
    const Point& p8
  ) noexcept {

  // TODO
  return true;
}

Point Octagon::calculate_centre() const {
  double centre_x = 0;
  double centre_y = 0;

  for (size_t i = 0; i < coordinates.get_size(); ++i) {
    centre_x += coordinates[i].x;
    centre_y += coordinates[i].y;
  }

  return Point{centre_x / 8, centre_y / 8};
}

Octagon::operator double() const {
  // TODO
  return 1;
}