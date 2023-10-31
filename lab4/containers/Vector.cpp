#include "Vector.hpp"

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(): capacity(1), size(0), array(AllocTraits::allocate(alloc, 1)) {}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(size_t capacity): capacity(capacity), size(0), array(AllocTraits::allocate(alloc, capacity + 1)) {}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(Allocator& alloc): capacity(1), size(0), array(AllocTraits::allocate(alloc, 1)), alloc(alloc) {}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(const Vector<T, Allocator>& vec): capacity(vec.capacity), size(vec.size), alloc(vec.alloc) {
  T* new_arr = AllocTraits::allocate(alloc, capacity);
  try {
    std::uninitialized_copy(vec.begin(), vec.end(), new_arr);

  } catch(...) {
    delete[] new_arr;
    throw;
  }
  
  array = new_arr;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(Vector<T, Allocator>&& oth) noexcept : capacity(oth.capacity), size(oth.size), array(oth.array) {
  oth.capacity = 0;
  oth.size = 0;
  oth.array = nullptr;
  alloc = std::move(oth.alloc);
}

template <typename T, typename Allocator>
Vector<T, Allocator>& Vector<T, Allocator>::operator=(Vector<T, Allocator>&& oth) noexcept {
  if (this == &oth) {
    return *this;
  }

  clear();
  AllocTraits::deallocate(alloc, array, capacity);

  capacity = oth.capacity;
  size = oth.size;
  array = oth.array;
  alloc = std::move(alloc);

  oth.capacity = 0;
  oth.size = 0;
  oth.array = nullptr;

  return *this;
}

template <typename T, typename Allocator>
Vector<T, Allocator>::Vector(const std::initializer_list<T>& lst) {
  T* new_arr = AllocTraits::allocate(alloc, lst.size() + 1);

  try {
    if (std::is_copy_constructible<T>::value) {
      std::uninitialized_copy(lst.begin(), lst.end(), new_arr);
    } else {
      std::uninitialized_move(lst.begin(), lst.end(), new_arr);
    }

  } catch(...) {
    delete[] new_arr;
    throw;
  }

  array = new_arr;
  capacity = lst.size() + 1;
  size = lst.size();
}

template <typename T, typename Allocator>
Vector<T, Allocator>& Vector<T, Allocator>::operator=(const Vector<T, Allocator>& vec) {
  if (this == &vec) {
    return *this;
  }

  clear();
  AllocTraits::deallocate(alloc, array, capacity);

  size = vec.size;
  capacity = vec.capacity;
  array = AllocTraits::allocate(alloc, capacity);

  try {
    std::uninitialized_copy(vec.begin(), vec.end(), array);
  } catch(...) {
    delete[] array;
    throw;
  }

  return *this;
}

template <typename T, typename Allocator>
T& Vector<T, Allocator>::operator[](size_t index) {
  return array[index];
}

template <typename T, typename Allocator>
const T& Vector<T, Allocator>::operator[](size_t index) const {
  return array[index];
}

template <typename T, typename Allocator>
Vector<T, Allocator>::~Vector() {
  for (size_t i = 0; i < size; ++i) {
    array[i].~T();
  }

  AllocTraits::deallocate(alloc, array, capacity);
}

template <typename T, typename Allocator>
size_t Vector<T, Allocator>::get_capacity() const {
  return capacity;
}

template <typename T, typename Allocator>
size_t Vector<T, Allocator>::get_size() const {
  return size;
}

template <typename T, typename Allocator>
const T& Vector<T, Allocator>::front() const {
  if (size == 0) {
    throw std::range_error("vector is empty");
  }

  return array[0];
}

template <typename T, typename Allocator>
T& Vector<T, Allocator>::front() {
  if (size == 0) {
    throw std::range_error("vector is empty");
  }

  return array[0];
}

template <typename T, typename Allocator>
const T& Vector<T, Allocator>::back() const {
  if (size == 0) {
    throw std::range_error("Array is empty");
  }

  return array[size - 1];
}

template <typename T, typename Allocator>
T& Vector<T, Allocator>::back() {
  if (size == 0) {
    throw std::range_error("Array is empty");
  }

  return array[size - 1];
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::reserve(size_t n) {
  if (n <= capacity) {
    return;
  }

  T* newArr = AllocTraits::allocate(alloc, n + 1);
  try {
    std::uninitialized_copy(begin(), end(), newArr);
  } catch(...) {
    delete[] newArr;
    throw;
  }

  for (size_t i = 0; i < size; ++i) {
    array[i].~T();
  }

  AllocTraits::deallocate(alloc, array, capacity);
  array = newArr;
  capacity = n + 1;    
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::resize(size_t n, const T& value) {
  if (n > capacity) {
    reserve(n);
  }

  for (size_t i = size; i < n; ++i) {
    AllocTraits::construct(alloc, array + i, value);
  }

  size = n;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::push_back(const T& data) {
  if (capacity - 1 == size) {
    reserve(2 * size);
  }

  AllocTraits::construct(alloc, array + size, std::move(data));
  ++size;
}

template <typename T, typename Allocator>
template <typename... Args>
void Vector<T, Allocator>::emplace_back(const Args& ...args) {
  if (capacity - 1 == size) {
    reserve(2 * size);
  }

  AllocTraits::construct(alloc, array + size, std::move_if_noexcept(args...));
  ++size;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::pop_back() {
  --size;
  array[size].~T();
}

template <typename T, typename Allocator>
T& Vector<T, Allocator>::at(size_t index) {
  if (index >= size) {
    throw std::range_error("Array index out of range!");
  }

  return array[index];
}

template <typename T, typename Allocator>
const T& Vector<T, Allocator>::at(size_t index) const {
  if (index >= size) {
    throw std::range_error("Array index out of range!");
  }

  return array[index];
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::clear() {
  for (size_t i = 0; i < size; ++i) {
    array[i].~T();
  }

  size = 0;
}

template <typename T, typename Allocator>
void Vector<T, Allocator>::shrink_to_fit() {
  if (size == 0) {
    reserve(1);
    return;
  }

  reserve(size);
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::empty() const {
  return size == 0;
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::operator==(const Vector<T, Allocator>& vec) const {
  if (size != vec.size) {
    return false;
  }

  for (size_t i = 0; i < size; ++i) {
    if (vec.array[i] != array[i]) {
      return false;
    }
  }

  return true;
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::operator!=(const Vector<T, Allocator>& vec) const {
  return !this->operator==(vec);
}

template <typename T, typename Allocator>
Vector<T, Allocator>::iterator::iterator(T* obj): obj_ptr(obj) {}

template <typename T, typename Allocator>
Vector<T, Allocator>::iterator::iterator(const iterator& rhs): obj_ptr(rhs.obj_ptr) {}

template <typename T, typename Allocator>
const T& Vector<T, Allocator>::iterator::operator*() const noexcept {
  return *obj_ptr;
}

template <typename T, typename Allocator>
T& Vector<T, Allocator>::iterator::operator*() noexcept {
  return *obj_ptr;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator& Vector<T, Allocator>::iterator::operator+=(uint32_t steps_count) {
  this->obj_ptr += 5;
  return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator& Vector<T, Allocator>::iterator::operator-=(uint32_t steps_count) {
  this->obj_ptr -= 5;
  return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator& Vector<T, Allocator>::iterator::operator++() {
  this->obj_ptr += 1;
  return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator& Vector<T, Allocator>::iterator::operator--() {
  this->obj_ptr -= 1;
  return *this;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator Vector<T, Allocator>::iterator::operator++(int) {
  iterator temp(this->obj_ptr);
  this->obj_ptr += 1;
  return *temp;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator Vector<T, Allocator>::iterator::operator--(int) {
  iterator temp(this->obj_ptr);
  this->obj_ptr -= 1;
  return *temp;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator Vector<T, Allocator>::iterator::operator-(uint32_t steps_count) const {
  iterator temp(this->obj_ptr);
  temp->obj_ptr -= steps_count;
  return temp;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator Vector<T, Allocator>::iterator::operator+(uint32_t steps_count) const {
  iterator temp(this->obj_ptr);
  temp->obj_ptr += steps_count;
  return temp;
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator Vector<T, Allocator>::begin() const {
  return iterator(&array[0]);
}

template <typename T, typename Allocator>
typename Vector<T, Allocator>::iterator Vector<T, Allocator>::end() const {
  return iterator(&array[size]);
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::iterator::operator==(const iterator& rhs) const {
  return obj_ptr == rhs.obj_ptr ? true : false;
}

template <typename T, typename Allocator>
bool Vector<T, Allocator>::iterator::operator!=(const iterator& rhs) const {
  return obj_ptr == rhs.obj_ptr ? false : true;
}

















