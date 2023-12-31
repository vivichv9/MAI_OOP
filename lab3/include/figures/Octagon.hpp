#ifndef OCTAGON_HPP_INCLUDED
#define OCTAGON_HPP_INCLUDED

#include "../interfaces/figure.hpp"

class Octagon : public Figure {
public:
  Octagon() = delete;
  Octagon(
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6,
    const Point& p7,
    const Point& p8
  );

  friend std::ostream& operator<<(std::ostream& os, const Octagon& rhs);
  friend std::istream& operator>>(std::istream& os, const Octagon& rhs);
  friend bool operator==(const Octagon& lhs, const Octagon& rhs);

  Point calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(    
    const Point& p1,
    const Point& p2,
    const Point& p3,
    const Point& p4,
    const Point& p5,
    const Point& p6,
    const Point& p7,
    const Point& p8
    ) noexcept;
};

#endif // OCTAGON_HPP_INCLUDED