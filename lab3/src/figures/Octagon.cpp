#include "../../include/figures/Octagon.hpp"

Octagon::Octagon() {

}

Octagon::Octagon(const Octagon& rhs) {
  coordinates = rhs.coordinates;
}

Octagon& Octagon::operator=(const Octagon& rhs) {
  coordinates = rhs.coordinates;
  return *this;
}

Octagon& Octagon::operator=(Octagon&& rhs) {
  coordinates = std::move(rhs.coordinates);
  return *this;
}