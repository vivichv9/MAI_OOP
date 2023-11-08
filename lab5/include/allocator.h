#ifndef ALLOCATOR_H_INCLUDED
#define ALLOCATOR_H_INCLUDED

#include <memory>
#include <vector> 

namespace mystd {

template <typename T, size_t CAP>
class allocator {
private:
  std::vector<T> data;
  size_t data_controller; 

public:
  allocator();
  T* allocate(size_t n);
  void deallocate(T* ptr, size_t n);

  template <typename... Args>
  void construct(T* ptr, Args... args);

  void destroy(T* ptr);
};

} // namespace mystd


#endif // ALLOCATOR_H_INCLUDED