#ifndef OCTAGON_HPP_INCLUDED
#define OCTAGON_HPP_INCLUDED

#include "../interfaces/figure.hpp"

class Octagon final : private Figure {
public:
  using Figure::calculate_centre;
  using Figure::operator double;

  Octagon();
  Octagon(const Octagon& rhs);
  Octagon& operator=(const Octagon& rhs);
  Octagon& operator=(Octagon&& rhs);

  friend std::ostream& operator<<(std::ostream& os, const Octagon& obj);
  friend std::istream& operator>>(std::istream& os, const Octagon& obj);

  size_t calculate_centre() const override;
  operator double() const override;
};

#endif