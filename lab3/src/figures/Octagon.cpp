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
    
  double sum_x = p1.get_x() + p2.get_x() + p3.get_x() + p4.get_x() + p5.get_x() + p6.get_x() + p7.get_x() + p8.get_x();
  double sum_y = p1.get_y() + p2.get_y() + p3.get_y() + p4.get_y() + p5.get_y() + p6.get_y() + p7.get_y() + p8.get_y();
  Point centre(sum_x / 8.0, sum_y / 8.0);

  double inaccuracy = 1e-10;

  // straight lines from center to corner
  double len_to_p1 = Point::line_len(centre, p1);
  double len_to_p2 = Point::line_len(centre, p2);
  double len_to_p3 = Point::line_len(centre, p3);
  double len_to_p4 = Point::line_len(centre, p4);
  double len_to_p5 = Point::line_len(centre, p5);
  double len_to_p6 = Point::line_len(centre, p6);
  double len_to_p7 = Point::line_len(centre, p7);
  double len_to_p8 = Point::line_len(centre, p8);

  if (
    std::abs(len_to_p1 - len_to_p2) < inaccuracy &&
    std::abs(len_to_p2 - len_to_p3) < inaccuracy &&
    std::abs(len_to_p3 - len_to_p4) < inaccuracy &&
    std::abs(len_to_p4 - len_to_p5) < inaccuracy && 
    std::abs(len_to_p5 - len_to_p6) < inaccuracy &&
    std::abs(len_to_p6 - len_to_p7) < inaccuracy &&
    std::abs(len_to_p7 - len_to_p8) < inaccuracy
  ) {
    return true;
  }

  return false;
}

Octagon::Octagon(
  const Point& p1,
  const Point& p2,
  const Point& p3,
  const Point& p4,
  const Point& p5,
  const Point& p6,
  const Point& p7,
  const Point& p8
  ) {
  
  bool is_octagon = validate(p1, p2, p3, p4, p5, p6, p7, p8);

  if (!is_octagon) {
    throw std::invalid_argument("Invalid points. Octagon can not created!");
  }

  coordinates = {p1, p2, p3, p4, p5, p6, p7, p8};
}

Point Octagon::calculate_centre() const {
  double centre_x = 0;
  double centre_y = 0;

  for (size_t i = 0; i < coordinates.get_size(); ++i) {
    centre_x += coordinates[i].get_x();
    centre_y += coordinates[i].get_y();
  }

  return Point(centre_x / 8.0, centre_y / 8.0);
}

Octagon::operator double() const {
  double side_len = Point::line_len(coordinates[0], coordinates[1]);

  return 2 * std::pow(side_len, 2) * (1 + std::sqrt(2));
}