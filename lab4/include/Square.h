#ifndef SQUARE_HPP_INCLUDED
#define SQUARE_HPP_INCLUDED

#include "Figure.h"

template <typename T>
class Square : public Figure<T> {
public:
  Square() = delete;
  Square(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4);
  virtual ~Square() = default;

  bool operator==(const Square<T>& rhs) const;

  Point<T> calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) noexcept;
};

#endif // SQUARE_HPP_INCLUDED