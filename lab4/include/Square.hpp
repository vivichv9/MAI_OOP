#ifndef SQUARE_HPP_INCLUDED
#define SQUARE_HPP_INCLUDED

#include "interfaces/Figure.hpp"

template <typename T>
class Square : public Figure<T> {
public:
  Square() = delete;
  Square(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4);

  friend std::ostream& operator<<(std::ostream& os, const Square& rhs);
  friend std::istream& operator>>(std::istream& os, const Square& rhs);

  friend bool operator==(const Square<T>& lhs, const Square<T>& rhs);

  Point<T> calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) noexcept;
};

#endif // SQUARE_HPP_INCLUDED