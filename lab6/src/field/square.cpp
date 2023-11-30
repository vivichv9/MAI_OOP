#include "square.h"

using namespace lab6;

Square::Square(double x, double y) {
  if (y > 500 || y < 0 || x > 500 || x < 0) {
    throw std::range_error("Square construct failed! Invalid input data");
  }

  this->x = x;
  this->y = y;
}

double Square::get_x() const noexcept {
  return x;
}

double Square::get_y() const noexcept {
  return y;
}

void Square::set_x(double x) {
  if (x > 500 || x < 0) {
    throw std::range_error("square::set_x, valid x is a 0 <= x <= 500");
  }

  this->x = x;
}

void Square::set_y(double y) {
  if (y > 500 || y < 0) {
    throw std::range_error("square::set_y, valid y is a 0 <= y <= 500");
  }

  this->y = y;
}


