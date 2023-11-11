#include "list.h"

template <typename T, typename Allocator>
mystd::list<T, Allocator>::list(std::initializer_list<value_type>& lst) noexcept {
  head = block_elem_ptr;

  auto last = lst.end() - 1;
  for (auto it = last; it != lst.begin(); --it) {
    push_front(*it);
  }
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::list(const allocator_type& alloc): alloc(alloc) {}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::list(const list<value_type, allocator_type>& rhs): alloc(rhs.alloc), block_elem_ptr(AllocTraits::allocate(alloc, 1)) {
  head = block_elem_ptr;
  size = rhs.size;

  if (size != 0) {
    Node* ptr = AllocTraits::allocate(alloc, rhs.size);

    head = ptr;
    for (auto it = rhs.cbegin(); it != rhs.cend(); ++it) {
      std::cout << *it << std::endl;
      AllocTraits::construct(alloc, ptr++, *it, ptr);
    }

    --ptr;
    ptr = block_elem_ptr;
  }
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::list(list<value_type, allocator_type>&& rhs) noexcept : block_elem_ptr(nullptr)  {
  alloc = std::move(rhs.alloc);

  head = rhs.head;
  rhs.head = rhs.block_elem_ptr;

  block_elem_ptr = rhs.block_elem_ptr;
  rhs.block_elem_ptr = nullptr;

  size = rhs.size;
  rhs.size = 0;
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>& mystd::list<T, Allocator>::operator=(const list<value_type, allocator_type>& rhs) {
  clear();

  head = block_elem_ptr;
  size = rhs.size;

  if (size != 0) {
    Node* ptr = AllocTraits::allocate(alloc, rhs.size);

    head = ptr;
    for (auto it = rhs.cbegin(); it != rhs.cend(); ++it) {
      std::cout << *it << std::endl;
      AllocTraits::construct(alloc, ptr++, *it, ptr);
    }

    --ptr;
    ptr = block_elem_ptr;
  }

  return *this;
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>& mystd::list<T, Allocator>::operator=(list<value_type, allocator_type>&& rhs) noexcept {
  clear();

  alloc = std::move(rhs.alloc);

  head = rhs.head;
  rhs.head = nullptr;

  size = rhs.size;
  rhs.size = 0;

  return *this;
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::~list() {
  clear();
  AllocTraits::deallocate(alloc, block_elem_ptr, 1);
}

template <typename T, typename Allocator>
bool mystd::list<T, Allocator>::operator==(const list<value_type, allocator_type>& rhs) const noexcept {
  if (size != rhs.size) {
    return false;
  }

  auto it_rhs = rhs.begin();
  for (auto it = begin(); it != end; ++it) {
    if (*it != *it_rhs) {
      return false;
    }

    ++it_rhs;
  }

  return true;
}

template <typename T, typename Allocator>
bool mystd::list<T, Allocator>::operator!=(const list<value_type, allocator_type>& rhs) const noexcept {
  return !(*this == rhs);
}

template <typename T, typename Allocator>
bool mystd::list<T, Allocator>::empty() const {
  return static_cast<bool>(size);
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::size_type mystd::list<T, Allocator>::max_size() const {
  return size;
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::reference mystd::list<T, Allocator>::front() {
  if (size != 0) {
    return head->obj;
  }

  throw std::range_error("List is empty!");
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::const_reference mystd::list<T, Allocator>::front() const {
  if (size != 0) {
    return head->obj;
  }

  throw std::range_error("List is empty!");
}

template <typename T, typename Allocator>
void mystd::list<T, Allocator>::clear() {
  for (size_t i = 0; i < size; ++i) {
    Node* temp = head;
    head = head->next;

    AllocTraits::destroy(alloc, temp);
    AllocTraits::deallocate(alloc, temp, 1);
  }

  head = block_elem_ptr;
  size = 0;
}

template <typename T, typename Allocator>
void mystd::list<T, Allocator>::push_front(const_reference obj) {
  ++size;
  Node* ptr = AllocTraits::allocate(alloc, 1);
  AllocTraits::construct(alloc, ptr, obj, head);
  head = ptr;
}

template <typename T, typename Allocator>
void mystd::list<T, Allocator>::pop_front() {
  if (size == 0) {
    throw std::range_error("List is empty");
  }
  
  Node* temp_head = head;
  head = head->next;

  AllocTraits::destroy(alloc, temp_head);
  AllocTraits::deallocate(alloc, temp_head, 1);
  --size;
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::begin() {
  return iterator(head);
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::cbegin() const {
  return iterator(head);
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::end() {
  return iterator(block_elem_ptr);
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::cend() const {
  return iterator(block_elem_ptr);
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::Node::Node(const T& value) : obj(value) {}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::Node::Node(const T& value, Node* next) : obj(value), next(next) {}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::iterator::iterator(Node* ptr) : ptr(ptr) {}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator& mystd::list<T, Allocator>::iterator::operator++() {
  this->ptr = this->ptr->next;
  return *this;
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator& mystd::list<T, Allocator>::iterator::operator++() const {
  this->ptr = this->ptr->next;
  return *this;
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator& mystd::list<T, Allocator>::iterator::operator+=(size_t rhs) {
  for (size_t i = 0; i < rhs; ++i) {
    ++*this;
  }

  return *this;
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator& mystd::list<T, Allocator>::iterator::operator+=(size_t rhs) const {
  for (size_t i = 0; i < rhs; ++i) {
    ++*this;
  }

  return *this;
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::iterator::operator+(size_t rhs) const {
  iterator temp = *this;
  temp += rhs;

  return temp;
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::reference mystd::list<T, Allocator>::iterator::operator*() {
  return this->ptr->obj;
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::const_reference mystd::list<T, Allocator>::iterator::operator*() const {
  return this->ptr->obj;
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator::pointer mystd::list<T, Allocator>::iterator::operator->() {
  return this->ptr;
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator::pointer mystd::list<T, Allocator>::iterator::operator->() const {
  return this->ptr;
}

template <typename T, typename Allocator>
bool mystd::list<T, Allocator>::iterator::operator==(const iterator& rhs) const {
  return ptr == rhs.ptr ? true : false;
}

template <typename T, typename Allocator>
bool mystd::list<T, Allocator>::iterator::operator!=(const iterator& rhs) const {
  return !(*this == rhs);
}
