#ifndef SIX_HPP_INCLUDED
#define SIX_HPP_INCLUDED

#include <iostream>
#include <cmath>
#include "containers/Vector.hpp"
#include "../src/containers/Vector.cpp"

class Six {  
private:
  Vector<unsigned char> number;

public:
  Six(uint64_t n);
  Six(const std::string& str);
  Six(const Six& oth) noexcept;
  Six(Six&& oth) noexcept;

  Six& operator=(Six&& oth) noexcept;
  Six& operator=(Six oth) noexcept;

  Six operator+(const Six& oth) const noexcept;
  Six operator-(const Six& oth) const;
  Six& operator++() noexcept;
  Six operator++(int) noexcept;
  Six& operator--();
  Six operator--(int);

  bool operator==(const Six& oth) const;
  bool operator!=(const Six& oth) const;
  bool operator>(const Six& oth) const;
  bool operator<(const Six& oth) const;

  friend std::ostream& operator<< (std::ostream& stream, const Six& six);

  void print() const;

private:
  void remove_zeroes(std::string& str) noexcept;
};

#endif // SIX_HPP_INCLUDED