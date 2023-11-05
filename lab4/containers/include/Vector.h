#ifndef VECTOR_HPP_INCLUDED
#define VECTOR_HPP_INCLUDED

#include <iostream>
#include <cstring>
#include <memory>

namespace mystd {

template <typename T, typename Allocator = std::allocator<T>>
class Vector final {
  using AllocTraits = std::allocator_traits<Allocator>;

private:
  size_t capacity = 0;
  size_t size = 0;
  T* array;
  Allocator alloc;

public:
  class iterator;

  Vector();   
  Vector(size_t);
  Vector(Allocator& alloc);
  Vector(const std::initializer_list<T>&);
  Vector(const Vector<T, Allocator>&);
  Vector(Vector<T, Allocator>&&) noexcept;
  Vector<T, Allocator>& operator=(const Vector<T, Allocator>&);
  Vector<T, Allocator>& operator=(Vector<T, Allocator>&&) noexcept;
  ~Vector();

  size_t get_size() const;
  size_t get_capacity() const;

  bool empty() const;
  bool operator==(const Vector<T, Allocator>&) const;
  bool operator!=(const Vector<T, Allocator>&) const;

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
  iterator begin() const;
  iterator end() const;

  class iterator {
  private:
    T* obj_ptr;
  
  public:
    iterator() = delete;
    iterator(T* obj);
    iterator(const iterator& rhs);
    
    const T& operator*() const noexcept;
    T& operator*() noexcept;
    iterator& operator++();
    iterator operator++(int);
    iterator operator--(int);
    iterator& operator--();
    iterator& operator+=(uint32_t steps_count);
    iterator& operator-=(uint32_t steps_count);
    iterator operator+(uint32_t steps_count) const;
    iterator operator-(uint32_t steps_count) const;

    bool operator==(const Vector<T, Allocator>::iterator& rhs) const;
    bool operator!=(const Vector<T, Allocator>::iterator& rhs) const;
  };
};

}
#endif // VECTOR_HPP_INCLUDED
