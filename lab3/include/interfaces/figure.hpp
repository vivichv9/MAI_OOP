#ifndef FIGURE_HPP_INCLUDED
#define FIGURE_HPP_INCLUDED

#include "../containers/Vector.hpp"
#include "../figures/Point.hpp"
#include "../../src/containers/Vector.cpp"
#include <vector>
#include <iostream>

class Figure {
protected:
  std::vector<Point> coordinates;
  
public:
  virtual operator double() const = 0;
  virtual Point calculate_centre() const = 0;
};

#endif // FIGURE_HPP_INCLUDED