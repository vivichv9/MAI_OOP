#include "../include/Seven.hpp"

#define ZERO_ASCII_CODE 48

Seven::Seven(const std::string& str) {
  number.reserve(str.size());
  for (int64_t i = str.size() - 1; i >= 0; --i) {
    if (str[i] > '6' || str[i] < '0') {
      throw std::invalid_argument("String contains invalid element");
    }

    number.push_back(str[i]);
  }
}

Seven::Seven(uint64_t n) {
  if (n == 0) {
    number.push_back('0');
  }

  while (n > 0) {
    unsigned char el = ZERO_ASCII_CODE + n % 10;

    if (el > ZERO_ASCII_CODE + 6 || el < ZERO_ASCII_CODE) {
      throw std::invalid_argument("Digit is over 6");
    }

    number.push_back(el);
    n /= 10;
  }
}

Seven::Seven(const Seven& oth) noexcept {
  number = oth.number;
}

Seven::Seven(Seven&& oth) noexcept {
  this->number = std::move(oth.number);
}

Seven& Seven::operator=(Seven&& oth) noexcept {
  this->number = std::move(oth.number);
  return *this;
}

Seven& Seven::operator=(Seven oth) noexcept {
  std::swap(this->number, oth.number);
  return *this;
}

Seven& Seven::operator++() noexcept {
  for (size_t i = 0; i < number.get_size(); ++i) {
    if (number[i] != '6') {
      ++number[i];
      return *this;
    }

    if (number[i] == '6') {
      number[i] = '0';
    }
  }

  number.push_back('1');
  return *this;
}

Seven Seven::operator++(int) noexcept {
  Seven temp = *this;
  ++*this;
  return temp;
}

Seven& Seven::operator--() {
  if (number.get_size() == 1 && number[0] == '0') {
    throw std::runtime_error("Decrement error. Num is 0");
  }

  for (size_t i = 0; i < number.get_size(); ++i) {
    if (number[i] != '0') {
      --number[i];
 
      if (&number[i] == &number[number.get_size() - 1]) {
        number.resize(number.get_size() - 1);
      }

      return *this;
    }

    if (number[i] == '0') {
      number[i] = '6';
    }
  }

  number.resize(number.get_size() - 1);
  return *this;
}

Seven Seven::operator--(int) {
  Seven* temp = this;
  --(*temp);
  return *temp;
}

Seven Seven::operator+(const Seven& oth) const noexcept {
  size_t min_size = std::min(number.get_size(), oth.number.get_size());
  size_t max_size = std::max(number.get_size(), oth.number.get_size());

  Seven new_obj{static_cast<uint64_t>(std::pow(10, max_size))};
  new_obj.number[new_obj.number.get_size() - 1] = '0';

  for (size_t i = 0; i < min_size; ++i) {
    new_obj.number[i] += (number[i] + oth.number[i] - 2 * ZERO_ASCII_CODE) % 7;
    new_obj.number[i + 1] += (number[i] + oth.number[i] - 2 * ZERO_ASCII_CODE + 1) / 7;
  
    if (oth.number.get_size() - max_size == 0 && 
      number[number.get_size() - 1] + oth.number[oth.number.get_size() - 1] - 2 * ZERO_ASCII_CODE > 6) {

      new_obj.number.resize(new_obj.number.get_size() + 1);
    }
  }

  return new_obj;
}

bool Seven::operator==(const Seven& oth) const {
  if (number.get_size() != oth.number.get_size()) {
    return false;
  }

  for (size_t i = 0; i < number.get_size(); ++i) {
    if (number[i] != oth.number[i]) {
      return false;
    }
  }

  return true;
}

bool Seven::operator!=(const Seven& oth) const {
  return *this == oth ? false : true;
}

bool Seven::operator>(const Seven& oth) const {
  if (oth.number.get_size() > number.get_size()) {
    return false;
  }

  for (int64_t i = number.get_size() - 1; i >= 0; --i) {
    if (number[i] > oth.number[i]) {
      return true;

    } else if (number[i] < oth.number[i]) {
      return false;
    }
  }

  return false;
}

Seven Seven::operator-(const Seven& oth) const {
  if (*this < oth) {
    throw std::runtime_error("Overflow");
  }

  std::string result;
  int carry = 0;

  size_t i = 0;
  result.reserve(number.get_size());
  while (i < number.get_size()) {
    int bit1 = (i < number.get_size()) ? number[i] - ZERO_ASCII_CODE : 0;
    int bit2 = (i < oth.number.get_size()) ? oth.number[i] - ZERO_ASCII_CODE : 0;

    int diff = bit1 - bit2 - carry;

    if (diff < 0) {
      diff += 7;
      carry = 1;
    } else {
      carry = 0;
    }
                      
    result.push_back(diff + ZERO_ASCII_CODE);
    i++;
  }

  auto last_it = --result.rend();
  int64_t count_zeroes = 0;
  for (auto it = result.rbegin(); it != last_it; ++it) {
    if (*it == '0') {
      ++count_zeroes;
    } else {
      break;
    }
  }

  result.resize(result.size() - count_zeroes);
  std::reverse(result.begin(), result.end());
  return Seven{result};
}

bool Seven::operator<(const Seven& oth) const {
  if (oth.number.get_size() > number.get_size()) {
    return true;
  }

  for (int64_t i = number.get_size() - 1; i >= 0; --i) {
    if (oth.number[i] > number[i]) {
      return true;

    } else if (oth.number[i] < number[i]) {
      return false;
    }
  }

  return false;
}

void Seven::print() const {
  if (number.get_size() == 0) {
    std::cout << '0' << std::endl;
    return;
  }

  for (int64_t i = number.get_size() - 1; i >= 0; --i) {
    std::cout << number[i];
  }

  std::cout << std::endl;
}

std::ostream& operator<< (std::ostream& stream, const Seven& six) {
  if (six.number.get_size() == 0) {
    stream << '0';
    return stream;
  }

  for (int64_t i = six.number.get_size() - 1; i >= 0; --i) {
    stream << six.number[i];
  }

  return stream;
}

void Seven::remove_zeroes(std::string& str) noexcept {
  auto last_it = --str.rend();
  int64_t count_zeroes = 0;
  for (auto it = str.rbegin(); it != last_it; ++it) {
    if (*it == '0') {
      ++count_zeroes;
    } else {
      break;
    }
  }
}
