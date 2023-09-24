#include "../include/Vector.hpp"

#include <memory>
#include <climits>

template <typename T>
lab2::Vector<T>::Vector() {
    size = 0;
    capacity = 1;
    array = reinterpret_cast<T*>(new int8_t[sizeof(T)]);
}

template <typename T>
lab2::Vector<T>::Vector(size_t capacity) {
    size = 0;
    this->capacity = capacity;
    array = reinterpret_cast<T*>(new int8_t[capacity * sizeof(T)]);
}

template <typename T>
lab2::Vector<T>::Vector(const Vector& vec): Vector(vec.capacity) {
    memcpy(array, vec.array, capacity * sizeof(T));
}

template <typename T>
lab2::Vector<T>::Vector(const std::initializer_list<T>& lst) {
    size = lst.size();
    capacity = size;
    array = new T[size];
    std::copy(lst.begin(), lst.end(), array);
}

template <typename T>
lab2::Vector<T>& lab2::Vector<T>::operator=(const lab2::Vector<T>& vec) {
    if (this == &vec) {
        return *this;
    }

    this->resize(vec.size);
    for (size_t i = 0; i < this->size; ++i) {
        this->array[i].~T();
        new (this->array + i) T(vec[i]);
    }
    return *this;
}

template <typename T>
T& lab2::Vector<T>::operator[](size_t index) {
    return array[index];
}

template <typename T>
const T& lab2::Vector<T>::operator[](size_t index) const {
    return array[index];
}

template <typename T>
lab2::Vector<T>::~Vector() {
    for (size_t i = 0; i < size; ++i){
        array[i].~T();
    }
    delete[] reinterpret_cast<int8_t*>(array);
}

template <typename T>
size_t lab2::Vector<T>::get_capacity() const {
    return capacity;
}

template <typename T>
size_t lab2::Vector<T>::get_size() const {
    return size;
}

template <typename T>
const T& lab2::Vector<T>::front() const {
    if (size == 0) {
        throw std::range_error("vector is empty");
    }

    return array[0];
}

template <typename T>
T& lab2::Vector<T>::front() {
    if (size == 0) {
        throw std::range_error("vector is empty");
    }

    return array[0];
}

template <typename T>
const T& lab2::Vector<T>::back() const {
    if (size == 0) {
        throw std::range_error("vector is empty");
    }

    return array[size - 1];
}

template <typename T>
T& lab2::Vector<T>::back() {
    if (size == 0) {
        throw std::range_error("vector is empty");
    }

    return array[size - 1];
}

template <typename T>
void lab2::Vector<T>::reserve(size_t n) {
    if (n <= size) {
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
void lab2::Vector<T>::resize(size_t n, const T& value) {
    if (n > capacity) {
        reserve(n);
    } 

    for (size_t i = size; i < n; ++i) {
        new (array + i) T(value);
    }

    if (n < size) {
        size = n;
    }
}

template <typename T>
void lab2::Vector<T>::push_back(const T& data) {
    if (capacity == size) {
        reserve(2 * size);
    }
    new (array + size) T(data);
    ++size;
}

template <typename T>
template <typename... Args>
void lab2::Vector<T>::emplace_back(const Args& ...args) {
    if (capacity == size) {
        reserve(2 * capacity);
    }

    new (array + size) T(args...);
    ++size;
}

template <typename T>
void lab2::Vector<T>::pop_back() {
    --size;
    array[size].~T();
}

template <typename T>
T& lab2::Vector<T>::at(size_t index) {
    if (index >= size) {
        throw std::range_error("Array index out of range!");
    }
    return array[index];
}

template <typename T>
const T& lab2::Vector<T>::at(size_t index) const {
    if (index >= size) {
        throw std::range_error("Array index out of range!");
    }
    return array[index];
}

template <typename T>
void lab2::Vector<T>::clear() {
    size_t sz_copy = size;

    for (size_t i = 0; i < sz_copy; ++i) {
        array[i].~T();
        size--;
    }
}

template <typename T>
void lab2::Vector<T>::shrink_to_fit() {
    if (size == 0) {
        reserve(1);
        return;
    }

    reserve(size);
}

template <typename T>
bool lab2::Vector<T>::empty() const {
    return size;
}

template <typename T>
bool lab2::Vector<T>::operator==(const lab2::Vector<T>& vec) const {
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
bool lab2::Vector<T>::operator!=(const lab2::Vector<T>& vec) const {
    return !this->operator==(vec);
}
