#pragma once

#include <iostream>
#include <vector>
#include <cmath>

class Six {
private:
  std::vector<unsigned char> number;

public:
  Six(uint32_t n);
  Six(const Six& oth) noexcept;
  Six(Six&& oth) noexcept;

  Six& operator=(Six&& oth) noexcept;
  Six& operator=(Six oth) noexcept;

  Six operator+(const Six& oth) const noexcept;
  Six operator-(const Six& oth) noexcept;
  Six& operator++() noexcept;
  Six operator++(int) noexcept;
  Six& operator--();
  Six operator--(int);

  bool operator==(const Six& oth) const;
  bool operator!=(const Six& oth) const;
  bool operator>(const Six& oth) const;
  bool operator<(const Six& oth) const;

  void print() const;
};