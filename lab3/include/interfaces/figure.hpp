#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED

#include "../containers/Vector.hpp"

#include <iostream>

struct Point {
  double x;
  double y;

  Point make_point(double x, double y) {
    return Point{x, y};
  }
};

class Figure {
protected:
  Vector<Point> coordinates;
  
public:
  virtual operator double() const = 0;
  virtual Point calculate_centre() const = 0;
};

#endif  