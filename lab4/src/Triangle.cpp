#include "Triangle.h"

template <typename T>
bool Triangle<T>::validate(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) noexcept {
  double sum_x = p1.get_x() + p2.get_x() + p3.get_x();
  double sum_y = p1.get_y() + p2.get_y() + p3.get_y();
  Point<T> centre(sum_x / 3.0, sum_y / 3.0);

  double inaccuracy = 1e-10;

  double len1 = Point<T>::line_len(centre, p1);
  double len2 = Point<T>::line_len(centre, p2);
  double len3 = Point<T>::line_len(centre, p3);

  if (std::abs(len1 - len2) <= inaccuracy && std::abs(len2 - len3) <= inaccuracy) {
    return true;
  }

  return false;
}

template <typename T>
Triangle<T>::Triangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) {
  bool is_triangle = validate(p1, p2, p3);

  if (!is_triangle) {
    throw std::invalid_argument("Invalid Point<T>s. Can not create triangle!");
  }

  this->coordinates = {p1, p2, p3};
}

template <typename U>
std::ostream& operator<<(std::ostream& os, Triangle<U>& rhs) {
  for (size_t i = 0; i < rhs.coordinates.get_size(); ++i) {
    os << rhs.coordinates[i];
  }
  return os;
}

template <typename U>
std::istream& operator>>(std::istream& is, Triangle<U>& rhs) {
  is >> rhs.coordinates[0] >> rhs.coordinates[1] >> rhs.coordinates[2];
  return is;
}

template <typename T>
Point<T> Triangle<T>::calculate_centre() const {
  double centre_x = 0;
  double centre_y = 0;

  for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
    centre_x += this->coordinates[i].get_x();
    centre_y += this->coordinates[i].get_y();
  }

  return Point<T>(centre_x / 3.0, centre_y / 3.0);
}

template <typename T>
bool Triangle<T>::operator==(const Triangle<T>& rhs) const {
  bool flag = false;

  for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
    flag = false;

    for (size_t j = 0; i < rhs.coordinates.get_size(); ++i) {
      if (this->coordinates[i] == rhs.coordinates[j]) {
        flag = true;
        continue;
      }
    }

    if (!flag) {
      return false;
    }
  }

  return true;
}

template <typename T>
Triangle<T>::operator double() const {
  double x2x1 = this->coordinates[1].get_x() - this->coordinates[0].get_x();
  double y3y1 = this->coordinates[2].get_y() - this->coordinates[0].get_y();
  double x3x1 = this->coordinates[2].get_x() - this->coordinates[0].get_x();
  double y2y1 = this->coordinates[1].get_y() - this->coordinates[0].get_y();

  double square = std::abs(x2x1 * y3y1 - x3x1 * y2y1) * 0.5;

  return square;
}

