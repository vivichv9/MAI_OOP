#ifndef TRIANGLE_HPP_INCLUDED
#define TRIANGLE_HPP_INCLUDED

#include "../interfaces/figure.hpp"

class Triangle : public Figure {
public:
  Triangle(const Point& p1, const Point& p2, const Point& p3);

  friend std::ostream& operator<<(std::ostream& os, Triangle& rhs);
  friend std::istream& operator>>(std::istream& os, Triangle& rhs);

  friend bool operator==(const Triangle& lhs, const Triangle& rhs);

  Point calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(const Point& p1, const Point& p2, const Point& p3) noexcept;
};

#endif // TRIANGLE_HPP_INCLUDED