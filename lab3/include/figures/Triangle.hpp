#ifndef TRIANGLE_HPP_INCLUDED
#define TRIANGLE_HPP_INCLUDED

#include "../interfaces/figure.hpp"

class Triangle : public Figure {
public:
  Triangle() = delete;
  explicit Triangle(const Triangle& rhs) = default;
  virtual ~Triangle() = default;

  Triangle& operator=(const Triangle& rhs) = default;
  Triangle& operator=(Triangle&& rhs) = default;

  Triangle(const Point& p1, const Point& p2, const Point& p3);
  Triangle(double x1, double y1, double x2, double y2, double x3, double y3);

  friend std::ostream& operator<<(std::ostream& os, const Triangle& rhs);
  friend std::istream& operator>>(std::istream& os, const Triangle& rhs);

  Point calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(/* TODO */);
};

#endif