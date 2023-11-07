#ifndef ALLOCATOR_H_INCLUDED
#define ALLOCATOR_H_INCLUDED

#include <memory>
#include <vector> 

namespace mystd {

template <typename T, size_t CAP = 1>
class allocator {
private:
  std::vector<T> data;

public:
  T* allocate(size_t n);
  void deallocate(T* ptr, size_t n);

  template <typename... Args>
  void construct(Args... args);

  template <typename... Args>
  void destroy(T* ptr, Args... args);
};

} // namespace mystd


#endif