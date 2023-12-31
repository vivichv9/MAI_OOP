#ifndef SQUARE_H_INCLUDED
#define SQUARE_H_INCLUDED

#include <stdexcept>
#include <complex>

namespace lab6 {

class Square {
private:
  double x;
  double y;

public:
  Square(double x, double y);

  [[nodiscard]] double get_x() const noexcept;

  [[nodiscard]] double get_y() const noexcept;

  void set_x(double x);

  void set_y(double y);

  static double len(const Square& s1, const Square& s2);
};

}

#endif