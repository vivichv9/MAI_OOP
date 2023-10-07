#ifndef TRIANGLE_HPP_INCLUDED
#define TRIANGLE_HPP_INCLUDED

#include "../interfaces/figure.hpp"

class Triangle final : private Figure {
public:
  using Figure::calculate_centre;
  using Figure::operator double;

  Triangle();
  Triangle(const Triangle& rhs);
  Triangle& operator=(const Triangle& rhs);
  Triangle& operator=(Triangle&& rhs);

  friend std::ostream& operator<<(std::ostream& os, const Triangle& obj);
  friend std::istream& operator>>(std::istream& os, const Triangle& obj);

  size_t calculate_centre() const override;
  operator double() const override;
};

#endif