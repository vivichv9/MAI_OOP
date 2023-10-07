#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED

#include <iostream>
#include "../containers/Vector.hpp"

struct Point {
  double x;
  double y;
};

class Figure {
protected:
  Vector<Point> coordinates;
  
public:
  virtual operator double() const = 0;
  virtual size_t calculate_centre() const = 0;
};

#endif  