#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>
#include <memory>
#include <cstring>

template<typename T>
class Vector {
private:
  size_t capacity = 0;
  size_t size = 0;
  T* array = nullptr;

public:
  Vector();   
  Vector(size_t);
  Vector(const std::initializer_list<T>&);
  Vector(const Vector&);
  Vector(Vector&&) noexcept;
  Vector& operator=(const Vector<T>&);
  Vector& operator=(Vector&&) noexcept;
  ~Vector();

  size_t get_size() const;
  size_t get_capacity() const;

  bool empty() const;
  bool operator==(const Vector<T>&) const;
  bool operator!=(const Vector<T>&) const;

  void resize(size_t, const T& = T());
  void push_back(const T&);
  void reserve(size_t n);
  void pop_back();
  void clear();
  void shrink_to_fit();

  template <typename... Args>
  void emplace_back(const Args& ...args);

  T& operator[](size_t);
  T& at(size_t);
  T& front();
  T& back();
  const T& operator[](size_t) const;
  const T& at(size_t) const;
  const T& back() const;
  const T& front() const;
};

#endif // VECTOR_HPP_INCLUDED
