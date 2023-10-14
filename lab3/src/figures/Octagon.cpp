#include "../../include/figures/Octagon.hpp"

bool Octagon::validate(/* TODO */) {
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