#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED 

#include <cmath>
#include <ostream>
#include <istream>

class Point {
private:
  double x;
  double y;

public:
  Point(double x, double y);

  void set_x(double x) noexcept;
  void set_y(double x) noexcept;
  double get_x() const noexcept;
  double get_y() const noexcept;

  static Point make_point(double x, double y);
  static double line_len(const Point& x, const Point& y);

  friend std::ostream& operator<<(std::ostream& os, const Point& rhs); 
  friend std::istream& operator>>(std::istream& is, Point& rhs);
};

#endif // POINT_HPP_INCLUDED