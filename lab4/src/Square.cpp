#include "../include/Square.hpp"

template <typename T>
bool Square<T>::validate(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) noexcept {
  double sum_x = p1.get_x() + p2.get_x() + p3.get_x() + p4.get_x();
  double sum_y = p1.get_y() + p2.get_y() + p3.get_y() + p4.get_y();
  Point<T> centre(sum_x / 4.0, sum_y / 4.0);

  double inaccuracy = 1e-10;

  // side len
  double len_p1p2 = Point<T>::line_len(p1, p2);
  double len_p1p4 = Point<T>::line_len(p1, p4);
  double len_p2p3 = Point<T>::line_len(p2, p3);
  double len_p3p4 = Point<T>::line_len(p3, p4);

  // straight lines from center to corner
  double len_to_p1 = Point<T>::line_len(centre, p1);
  double len_to_p2 = Point<T>::line_len(centre, p2);
  double len_to_p3 = Point<T>::line_len(centre, p3);
  double len_to_p4 = Point<T>::line_len(centre, p4);
  
  if (std::abs(len_p1p2 - len_p1p4) < inaccuracy &&
        std::abs(len_p1p2 - len_p2p3) < inaccuracy &&
          std::abs(len_p3p4 - len_p1p2) < inaccuracy) {
    
    if (std::abs(len_to_p1 - len_to_p2) < inaccuracy &&
          std::abs(len_to_p2 - len_to_p3) < inaccuracy &&
            std::abs(len_to_p3 - len_to_p4) < inaccuracy) {
      
      return true;
    }
  }

  return false;
}

template <typename T>
Square<T>::Square(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3, const Point<T>& p4) {
  bool is_valid = validate(p1, p2, p3, p4);

  if (!is_valid) {
    throw std::invalid_argument("Invalid Point<T>s. Square can not created!");
  }

  this->coordinates = {p1, p2, p3, p4};
}

template <typename T>
Point<T> Square<T>::calculate_centre() const {
  double centre_x = 0;
  double centre_y = 0;

  for (size_t i = 0; i < this->coordinates.get_size(); ++i) {
    centre_x += this->coordinates[i].get_x();
    centre_y += this->coordinates[i].get_y();
  }

  return Point<T>(centre_x / 4.0, centre_y / 4.0);
}

template <typename T>
bool Square<T>::operator==(const Square<T>& rhs) {
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
Square<T>::operator double() const {
  return std::pow(Point<T>::line_len(this->coordinates[0], this->coordinates[1]), 2);
}