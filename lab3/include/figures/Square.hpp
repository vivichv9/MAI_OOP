#ifndef SQUARE_HPP_INCLUDED
#define SQUARE_HPP_INCLUDED

#include "../interfaces/figure.hpp"

class Square : public Figure {
public:
  Square() = delete;
  explicit Square(const Square& rhs) = default;
  Square& operator=(const Square& rhs) = default;
  Square& operator=(Square&& rhs) = default;
  virtual ~Square() = delete;

  Square(const Point& p1, const Point& p2, const Point& p3, const Point& p4);

  friend std::ostream& operator<<(std::ostream& os, const Square& rhs);
  friend std::istream& operator>>(std::istream& os, const Square& rhs);

  Point calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(const Point& p1, const Point& p2, const Point& p3, const Point& p4) noexcept;
};

#endif // SQUARE_HPP_INCLUDED