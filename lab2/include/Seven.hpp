#ifndef SIX_HPP_INCLUDED
#define SIX_HPP_INCLUDED

#include <iostream>
#include <cmath>
#include "containers/Vector.hpp"
#include "../src/containers/Vector.cpp"

class Seven {  
private:
  Vector<unsigned char> number;

public:
  Seven(uint64_t n);
  Seven(const std::string& str);
  Seven(const Seven& oth) noexcept;
  Seven(Seven&& oth) noexcept;

  Seven& operator=(Seven&& oth) noexcept;
  Seven& operator=(Seven oth) noexcept;

  Seven operator+(const Seven& oth) const noexcept;
  Seven operator-(const Seven& oth) const;
  Seven& operator++() noexcept;
  Seven operator++(int) noexcept;
  Seven& operator--();
  Seven operator--(int);

  bool operator==(const Seven& oth) const;
  bool operator!=(const Seven& oth) const;
  bool operator>(const Seven& oth) const;
  bool operator<(const Seven& oth) const;

  friend std::ostream& operator<< (std::ostream& stream, const Seven& six);

  void print() const;

private:
  void remove_zeroes(std::string& str) noexcept;
};

#endif // SIX_HPP_INCLUDED