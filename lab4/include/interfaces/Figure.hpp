#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED

#include "../../containers/Vector.hpp"
#include "../Point.hpp"

#include <iostream>

template <typename T>
class Figure {
protected:
  Vector<Point<T>> coordinates;
  
public:
  virtual operator double() const = 0;
  virtual Point<T> calculate_centre() const = 0;
};

#endif // FIGURE_HPP_INCLUDED