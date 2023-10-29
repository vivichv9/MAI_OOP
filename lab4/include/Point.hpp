#ifndef POINT_HPP_INCLUDED
#define POINT_HPP_INCLUDED 

#include <cmath>
#include <ostream>
#include <istream>

template <typename T>
class Point {
private:
  T x;
  T y;

public:
  Point(const T& x, const T& y);

  void set_x(const T& x) noexcept;
  void set_y(const T& x) noexcept;
  T& get_x() noexcept;
  T& get_y() noexcept;
  const T& get_x() const noexcept;
  const T& get_y() const noexcept;

  friend bool operator==(const Point<T>& lhs, const Point<T>& rhs);

  static double line_len(const Point<T>& x, const Point<T>& y);

  friend std::ostream& operator<<(std::ostream& os, const Point<T>& rhs); 
  friend std::istream& operator>>(std::istream& is, Point<T>& rhs);
};

#endif // POINT_HPP_INCLUDED