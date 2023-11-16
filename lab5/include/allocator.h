#ifndef ALLOCATOR_H_INCLUDED
#define ALLOCATOR_H_INCLUDED

#define DEBUG // RELEASE or DEBUG. For test use DEBUG

#include <memory>
#include <vector> 
#include <stdexcept>

namespace mystd {

template <typename T, size_t Cap>
class allocator {
public:
  template <class U> 
  struct rebind_alloc {
      typedef allocator<U, Cap> other;
  };

  using value_type = T;
  using pointer = T*;
  using const_pointer = const T*;
  using reference = T&;
  using const_reference = const T&;
  using size_type = size_t;

  template <typename U>
  using rebind = rebind_alloc<U>;

private:
  std::vector<value_type> data;
  size_type current_free_index = 0; 

public:
  allocator() noexcept;
  virtual ~allocator() = default;
  allocator(const allocator& rhs) noexcept;
  allocator& operator=(const allocator& rhs) noexcept;

  allocator(allocator&&) = delete;
  allocator& operator=(allocator&&) = delete;

  pointer allocate(size_type n);
  void deallocate(pointer ptr, size_type n);

  template <typename... Args>
  void construct(pointer ptr, Args... args);

  void destroy(pointer ptr);

// for tests
#ifndef RELEASE
public:
  const std::vector<T>& get_data() {
    return data;
  }

  size_t get_capacity() {
    return data.capacity();
  }

  size_t get_index() {
    return current_free_index;
  }
#endif // ifndef RELEASE

};

} // namespace mystd


#endif // ifndef ALLOCATOR_H_INCLUDED