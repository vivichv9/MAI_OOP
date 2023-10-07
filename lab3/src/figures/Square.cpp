#include "../../include/figures/Square.hpp"

Square::Square() {

}

Square::Square(const Square& rhs) {
  coordinates = rhs.coordinates;
}

Square& Square::operator=(const Square& rhs) {
  coordinates = rhs.coordinates;
  return *this;
}

Square& Square::operator=(Square&& rhs) {
  coordinates = std::move(rhs.coordinates);
  return *this;
}