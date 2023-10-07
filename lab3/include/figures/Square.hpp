#ifndef SQUARE_HPP_INCLUDED
#define SQUARE_HPP_INCLUDED

#include "../interfaces/figure.hpp"

#include <iostream>

class Square final : private Figure {
public:
  using Figure::calculate_centre;
  using Figure::operator double;

  Square();
  Square(const Square& rhs);
  Square& operator=(const Square& rhs);
  Square& operator=(Square&& rhs);

  friend std::ostream& operator<<(std::ostream& os, const Square& obj);
  friend std::istream& operator>>(std::istream& os, const Square& obj);

  size_t calculate_centre() const override;
  operator double() const override;
};

#endif