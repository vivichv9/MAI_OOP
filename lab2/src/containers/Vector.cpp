#include "../include/containers/Vector.hpp"

#include <memory>
#include <climits>

template <typename T>
Vector<T>::Vector() {
    size = 0;
    capacity = 1;
    array = reinterpret_cast<T*>(new int8_t[sizeof(T)]);
}

template <typename T>
Vector<T>::Vector(size_t capacity): capacity(capacity), size(0) {
    array = reinterpret_cast<T*>(new int8_t[capacity * sizeof(T)]);
}

template <typename T>
Vector<T>::Vector(const Vector<T>& vec) {
    size = vec.size;
    capacity = vec.capacity;
    T* new_arr = reinterpret_cast<T*>(new int8_t[capacity * sizeof(T)]);

    try {
        std::uninitialized_copy(vec.array, vec.array + vec.size, new_arr);
    } catch (...) {
        delete[] reinterpret_cast<char *>(new_arr);
        throw;
    }
    array = new_arr;
}

template <typename T>
Vector<T>::Vector(Vector<T>&& oth) noexcept : capacity(oth.capacity), size(oth.size), array(oth.array) {
    oth.capacity = 0;
    oth.size = 0;
    oth.array = nullptr;
}

template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& oth) noexcept {
    this->capacity = oth.capacity;
    this->size = oth.size;
    this->array = oth.array;

    oth.array = nullptr;
    oth.capacity = 0;
    oth.size = 0;

    return *this;
}

template <typename T>
Vector<T>::Vector(const std::initializer_list<T>& lst) {
    T* new_arr = reinterpret_cast<T*>(new int8_t[lst.size() * sizeof(T)]);
    try {
        std::uninitialized_copy(lst.begin(), lst.end(), new_arr);
    } catch (...) {
        delete[] reinterpret_cast<char*>(new_arr);
        throw;
    }
    array = new_arr;
    capacity = lst.size();
    size = lst.size();
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& vec) {
  if (this == &vec) {
    return *this;
  }

  size = vec.size;
  capacity = vec.capacity;
  array = reinterpret_cast<T*>(new int8_t[capacity * sizeof(T)]);
  std::copy(&vec.front(), &vec.back(), array);
  return *this;
}

template <typename T>
T& Vector<T>::operator[](size_t index) {
    return array[index];
}

template <typename T>
const T& Vector<T>::operator[](size_t index) const {
    return array[index];
}

template <typename T>
Vector<T>::~Vector() {
    for (size_t i = 0; i < size; ++i){
        array[i].~T();
    }
    delete[] reinterpret_cast<int8_t*>(array);
}

template <typename T>
size_t Vector<T>::get_capacity() const {
    return capacity;
}

template <typename T>
size_t Vector<T>::get_size() const {
    return size;
}

template <typename T>
const T& Vector<T>::front() const {
    if (size == 0) {
        throw std::range_error("vector is empty");
    }

    return array[0];
}

template <typename T>
T& Vector<T>::front() {
    if (size == 0) {
        throw std::range_error("vector is empty");
    }

    return array[0];
}

template <typename T>
const T& Vector<T>::back() const {
    if (size == 0) {
        throw std::range_error("vector is empty");
    }

    return array[size];
}

template <typename T>
T& Vector<T>::back() {
    if (size == 0) {
        throw std::range_error("vector is empty");
    }

    return array[size - 1];
}

template <typename T>
void Vector<T>::reserve(size_t n) {
    if (n <= capacity) {
        return;
    }

    T* newArr = reinterpret_cast<T*>(new int8_t[n * sizeof(T)]);

    try {
        std::uninitialized_copy(array, array + size, newArr);
    } catch (...) {
        delete[] reinterpret_cast<int8_t*>(newArr);
        throw;
    }

    for (size_t i = 0; i < size; ++i) {
        array[i].~T();
    }

    delete[] reinterpret_cast<int8_t*>(array);
    array = newArr;
    capacity = n;    
}

template <typename T>
void Vector<T>::resize(size_t n, const T& value) {
    if (n > capacity) {
        reserve(n);
    } 

    for (size_t i = size; i < n; ++i) {
        new (array + i) T(value);
    }

    size = n;
}

template <typename T>
void Vector<T>::push_back(const T& data) {
    if (capacity == size) {
        reserve(2 * size);
    }
    new (array + size) T(data);
    ++size;
}

template <typename T>
template <typename... Args>
void Vector<T>::emplace_back(const Args& ...args) {
    if (capacity == size) {
        reserve(2 * capacity);
    }

    new (array + size) T(args...);
    ++size;
}

template <typename T>
void Vector<T>::pop_back() {
    --size;
    array[size].~T();
}

template <typename T>
T& Vector<T>::at(size_t index) {
    if (index >= size) {
        throw std::range_error("Array index out of range!");
    }
    return array[index];
}

template <typename T>
const T& Vector<T>::at(size_t index) const {
    if (index >= size) {
        throw std::range_error("Array index out of range!");
    }
    return array[index];
}

template <typename T>
void Vector<T>::clear() {
    size_t sz_copy = size;

    for (size_t i = 0; i < sz_copy; ++i) {
        array[i].~T();
        size--;
    }
}

template <typename T>
void Vector<T>::shrink_to_fit() {
    if (size == 0) {
        reserve(1);
        return;
    }

    reserve(size);
}

template <typename T>
bool Vector<T>::empty() const {
    return size == 0;
}

template <typename T>
bool Vector<T>::operator==(const Vector<T>& vec) const {
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

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& vec) const {
    return !this->operator==(vec);
}
