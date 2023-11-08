#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <memory>

namespace mystd {

template <typename T, typename Allocator = std::allocator<T>>
class list final {
public:
  using value_type = T;
  using allocator_type = Allocator;
  using size_type = size_t;
  using reference = value_type&;
  using const_reference = const reference;

private:
  struct Node;
  using node_pointer = Node*; 

  using Alloc = typename std::allocator_traits<Allocator>::rebind_alloc<Node>;
  Alloc alloc;
  using AllocTraits = std::allocator_traits<Alloc>;

  node_pointer head = nullptr;
  node_pointer block_elem_ptr = AllocTraits::allocate(alloc, 1);
  node_pointer before_begin_ptr = AllocTraits::allocate(alloc, 1);
  size_type size = 0;

public:
  class iterator;

  using pointer = AllocTraits::pointer;
  using const_pointer =	AllocTraits::const_pointer;

  list(std::initializer_list<value_type>& lst);
  list(const allocator_type& alloc);
  list(const_reference obj);
  list(const list<value_type, allocator_type>& rhs);
  list(list<value_type, allocator_type>&& rhs) noexcept;
  list& operator=(const list<value_type, allocator_type>& rhs);
  list& operator=(list<value_type, allocator_type>&& rhs) noexcept;
  ~list();

  bool operator==(const list<value_type, allocator_type>& rhs) const noexcept;
  bool operator!=(const list<value_type, allocator_type>& rhs) const noexcept;
  bool empty() const;
  bool max_size() const;

  reference front();
  const_reference front() const;

  void clear();
  void push_back(const_reference obj);
  void push_front(const_reference obj);
  void pop_back();
  void pop_front();

  iterator begin();
  const iterator cbegin() const;
  iterator end();
  const iterator cend() const;

private:
  struct Node {
    T obj;
    Node* next = nullptr;

    Node(const T& value);
    Node(const T& value, Node* next);
  };

  class iterator {
  private:
    Node* ptr;

  public:
    using difference_type = int;
    using value_type = list::value_type;
    using reference = list::value_type&;
    using pointer = list::value_type*;
    using iterator_category = std::forward_iterator_tag;

    iterator(Node* ptr);

    iterator& operator++();
    const iterator& operator++() const;
    iterator& operator--();
    const iterator& operator--() const;

    iterator& operator+=(size_t rhs);
    const iterator& operator+=(size_t rhs) const;
    iterator& operator-=(size_t rhs);
    const iterator& operator-=(size_t rhs) const;

    iterator operator+(size_t rhs) const;
    iterator operator-(size_t rhs) const;
    
    reference operator*();
    const reference operator*() const;

    pointer operator->();
    const pointer operator->() const;
  };
};
  
} // namespace mystd


#endif // LIST_H_INCLUDED