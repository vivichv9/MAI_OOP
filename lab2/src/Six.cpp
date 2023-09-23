#include "../include/Six.hpp"

#define ZERO_ASCII_CODE 48

Six::Six(uint32_t n) {
  if (n == 0) {
    number.push_back('0');
  }

  while (n > 0) {
    unsigned char el = ZERO_ASCII_CODE + n % 10;

    if (el > ZERO_ASCII_CODE + 5 || el < ZERO_ASCII_CODE) {
      throw std::invalid_argument("Digit is over 5");
    }

    number.push_back(el);
    n /= 10;
  }
}

Six::Six(const Six& oth) noexcept {
  this->number = oth.number;
}

Six::Six(Six&& oth) noexcept {
  this->number = std::move(oth.number);
}

Six& Six::operator=(Six&& oth) noexcept {
  this->number = std::move(oth.number);
  return *this;
}

Six& Six::operator=(Six oth) noexcept {
  std::swap(this->number, oth.number);
  return *this;
}

Six& Six::operator++() noexcept {
  for (auto it = number.begin(); it != number.end(); ++it) {
    if (*it != '5') {
      ++(*it);
      return *this;
    }

    if (*it == '5') {
      *it = '0';
    }
  }

  number.push_back('1');
  return *this;
}

Six Six::operator++(int) noexcept {
  Six* temp = this;
  ++(*temp);
  return *temp;
}

Six& Six::operator--() {
  if (number.size() == 1 && number[0] == '0') {
    throw std::runtime_error("Decrement error. Num is 0");
  }

  for (auto it = number.begin(); it != number.end(); ++it) {
    if (*it != '0') {
      --(*it);

      if (it + 1 == number.end()) {
        number.resize(number.size() - 1);
      }

      return *this;
    }

    if (*it == '0') {
      *it = '5';
    }
  }

  number.resize(number.size() - 1);
  return *this;
}

Six Six::operator--(int) {
  Six* temp = this;
  --(*temp);
  return *temp;
}

Six Six::operator+(const Six& oth) const noexcept {
  size_t min_size = std::min(number.size(), oth.number.size());
  size_t max_size = std::max(number.size(), oth.number.size());

  Six new_obj{std::pow(10, max_size - 1)};
  new_obj.number[new_obj.number.size() - 1] = '0';

  for (size_t i = 0; i < min_size; ++i) {
    new_obj.number[i] += (number[i] + oth.number[i] - 2 * ZERO_ASCII_CODE) % 6;
    new_obj.number[i + 1] += (number[i] + oth.number[i] - 2 * ZERO_ASCII_CODE + 1) / 6;
  
    if (oth.number.size() - max_size == 0 && 
        number[number.size() - 1] + oth.number[oth.number.size() - 1] - 2 * ZERO_ASCII_CODE > 5) {

      new_obj.number.resize(new_obj.number.size() + 1);
    }
  }

  return new_obj;
}

bool Six::operator==(const Six& oth) const {
  if (number.size() != oth.number.size()) {
    return false;
  }

  for (size_t i = 0; i < number.size(); ++i) {
    if (number[i] != oth.number[i]) {
      return false;
    }
  }

  return true;
}

bool Six::operator!=(const Six& oth) const {
  return *this == oth ? false : true;
}

bool Six::operator>(const Six& oth) const {
  if (oth.number.size() > number.size()) {
    return false;
  }

  for (size_t i = 0; i < number.size(); ++i) {
    if (number[i] > oth.number[i]) {
      return true;

    } else if (number[i] < oth.number[i]) {
      return false;
    }
  }

  return false;
}

bool Six::operator<(const Six& oth) const {
  if (oth.number.size() > number.size()) {
    return true;
  }

  for (size_t i = 0; i < number.size(); ++i) {
    if (oth.number[i] > number[i]) {
      return true;

    } else if (oth.number[i] < number[i]) {
      return false;
    }
  }

  return false;
}

void Six::print() const {
  for (auto it = number.rbegin(); it != number.rend(); ++it)  {
    std::cout << *it;
  }

  std::cout << std::endl;
}
