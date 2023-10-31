#ifndef OCTAGON_HPP_INCLUDED
#define OCTAGON_HPP_INCLUDED

#include "interfaces/Figure.hpp"

template <typename T>
class Octagon : public Figure<T> {
public:
  Octagon() = delete;
  Octagon(
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6,
    const Point<T>& p7,
    const Point<T>& p8
  );

  virtual ~Octagon() = default;

  friend bool operator==(const Octagon<T>& lhs, const Octagon<T>& rhs);

  Point<T> calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(    
    const Point<T>& p1,
    const Point<T>& p2,
    const Point<T>& p3,
    const Point<T>& p4,
    const Point<T>& p5,
    const Point<T>& p6,
    const Point<T>& p7,
    const Point<T>& p8
    ) noexcept;
};

#endif // OCTAGON_HPP_INCLUDED