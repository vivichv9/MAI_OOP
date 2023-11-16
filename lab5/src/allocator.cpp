#include "allocator.h"

template <typename T, size_t Cap>
mystd::allocator<T, Cap>::allocator() noexcept {
  data.reserve(Cap);
}

template <typename T, size_t Cap>
mystd::allocator<T, Cap>::allocator(const allocator& rhs) noexcept {
  data.reserve(rhs.data.capacity());
}

template <typename T, size_t Cap>
mystd::allocator<T, Cap>& mystd::allocator<T, Cap>::operator=(const allocator& rhs) noexcept {
  data.clear();
  data.reserve(rhs.data.capacity());
  current_free_index = 0;
}

template <typename T, size_t Cap>
typename mystd::allocator<T, Cap>::pointer mystd::allocator<T, Cap>::allocate(size_type n) {
  if (data.capacity() < current_free_index + n) {
    throw std::runtime_error("Allocator capacity overflow with current input value");
  }

  current_free_index += n;
  return &data[current_free_index - n];
}

template <typename T, size_t Cap>
void mystd::allocator<T, Cap>::deallocate(pointer ptr, size_type n) {}

template <typename T, size_t Cap>
template <typename... Args>
void mystd::allocator<T, Cap>::construct(pointer ptr, Args... args) {
  new (ptr) value_type(args...);
}

template <typename T, size_t Cap>
void mystd::allocator<T, Cap>::destroy(pointer ptr) {
  ptr->~value_type();
}



