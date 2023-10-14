#include "../../include/figures/Square.hpp"

bool Square::validate(/* TODO */) {
  // TODO
  return true;
}

Point Square::calculate_centre() const {
  double centre_x = 0;
  double centre_y = 0;

  for (size_t i = 0; i < coordinates.get_size(); ++i) {
    centre_x += coordinates[i].x;
    centre_y += coordinates[i].y;
  }

  return Point{centre_x / 4, centre_y / 4};
}

Square::operator double() const {
  // TODO
  return 1;
}