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
  Square(
    double x1,
    double y1,
    double x2, 
    double y2,
    double x3,
    double y3,
    double x4,
    double y4
  );

  friend std::ostream& operator<<(std::ostream& os, const Square& rhs);
  friend std::istream& operator>>(std::istream& os, const Square& rhs);

  Point calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(/* TODO */);
};

#endif