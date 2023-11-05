#ifndef TRIANGLE_HPP_INCLUDED
#define TRIANGLE_HPP_INCLUDED

#include "Figure.h"

template <typename T>
class Triangle : public Figure<T> {
public:
  Triangle() = delete;
  Triangle(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3);
  virtual ~Triangle() = default;

  template <typename U>
  friend std::ostream& operator<<(std::ostream& os, Triangle<U>& rhs);
  
  template <typename U>
  friend std::istream& operator>>(std::istream& os, Triangle<U>& rhs);

  bool operator==(const Triangle<T>& rhs) const;

  Point<T> calculate_centre() const override;
  operator double() const override;

private:
  static bool validate(const Point<T>& p1, const Point<T>& p2, const Point<T>& p3) noexcept;
};

#endif // TRIANGLE_HPP_INCLUDED