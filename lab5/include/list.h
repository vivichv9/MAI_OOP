#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <memory>

namespace mystd {

template <typename T, typename Alloc = std::allocator<T>>
class list {
  struct Node;
  
private:
  Node* head = nullptr;
  size_t size;

public:
  list(const T& obj);
  list(const list<T, Alloc>& rhs);
  list(list<T, Alloc>&& rhs) noexcept;
  list& operator=(const list<T, Alloc>& rhs);
  list& operator=(list<T, Alloc>&& rhs) noexcept;

private:
  struct Node {
    T obj;
    Node* next = nullptr; 
  };
};
  
} // namespace mystd


#endif