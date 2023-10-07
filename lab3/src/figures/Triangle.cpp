#include "../../include/figures/Triangle.hpp"

Triangle::Triangle() {

}

Triangle::Triangle(const Triangle& rhs) {
  coordinates = rhs.coordinates;
}

Triangle& Triangle::operator=(const Triangle& rhs) {
  coordinates = rhs.coordinates;
  return *this;
}

Triangle& Triangle::operator=(Triangle&& rhs) {
  coordinates = std::move(rhs.coordinates);
  return *this;
}