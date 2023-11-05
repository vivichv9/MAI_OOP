#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED

#include "Vector.h"
#include "Point.h"

#include <iostream>

template <typename T>
class Figure {
protected:
  mystd::Vector<Point<T>> coordinates;
  
public:
  virtual operator double() const = 0;
  virtual Point<T> calculate_centre() const = 0;
  virtual ~Figure() = default;
};

#endif // FIGURE_HPP_INCLUDED