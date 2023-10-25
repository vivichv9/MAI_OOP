#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED 

class Point {
private:
  double x;
  double y;

public:
  void set_x(double x) noexcept;
  void set_y(double x) noexcept;
  double get_x() const noexcept;
  double get_y() const noexcept;

  static Point make_point(double x, double y);

  friend std::ostream& operator<<(std::ostream& os, const Triangle& rhs); 
  friend std::istream& operator>>(std::istream& os, const Triangle& rhs);
};

#endif // POINT_HPP_INCLUDED