#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include <memory>
#include <iostream>
#include <initializer_list>

#define DEBUG // DEBUG or RELEASE for test use DEBUG

namespace mystd {

template <typename T, typename Allocator = std::allocator<T>>
class list final {
public:
  class iterator;
  using value_type = T;
  using allocator_type = Allocator;
  using size_type = size_t;
  using reference = T&;
  using const_reference = const T&;

#ifdef RELEASE
private:
#endif // ifdef RELEASE

#ifdef DEBUG
public:
#endif // ifdef DEBUG

  struct Node;
  using node_pointer = Node*; 

  using Alloc = typename std::allocator_traits<Allocator>::template rebind_alloc<Node>;
  Alloc alloc;
  using AllocTraits = std::allocator_traits<Alloc>;

  node_pointer head = nullptr;
  node_pointer block_elem_ptr = AllocTraits::allocate(alloc, 1);
  size_type size = 0;

public:
  using pointer = typename AllocTraits::pointer;
  using const_pointer = typename AllocTraits::const_pointer;

  list();
  list(const allocator_type& alloc);
  list(const list<value_type, allocator_type>& rhs);
  list(list<value_type, allocator_type>&& rhs) noexcept;
  list<value_type, allocator_type>& operator=(const list<value_type, allocator_type>& rhs);
  list<value_type, allocator_type>& operator=(list<value_type, allocator_type>&& rhs) noexcept;
  ~list();

  bool operator==(const list<value_type, allocator_type>& rhs) const noexcept;
  bool operator!=(const list<value_type, allocator_type>& rhs) const noexcept;
  bool empty() const;

  size_type max_size() const;

  reference front();
  const_reference front() const;

  void clear();
  void insert_after(const_reference obj, const iterator& it);
  void erase_after(const iterator& it);
  void push_front(const_reference obj);
  void pop_front();

  iterator begin();
  const iterator cbegin() const;

  iterator end();
  const iterator cend() const;

#ifdef RELEASE
private:
#endif // ifdef RELEASE

#ifdef DEBUG
public:
#endif // ifdef DEBUG
  struct Node {
    T obj;
    Node* next = nullptr;

    Node(const T& value);
    Node(const T& value, Node* next);
  };

public:
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

    iterator& operator+=(size_t rhs);
    const iterator& operator+=(size_t rhs) const;

    iterator operator+(size_t rhs) const;
    
    reference operator*();
    const_reference operator*() const;

    pointer operator->();
    const pointer operator->() const;

    bool operator==(const iterator& rhs) const;
    bool operator!=(const iterator& rhs) const;

    Node* get_ptr() const;
  };
};
  
} // namespace mystd

#endif // ifndef LIST_H_INCLUDED