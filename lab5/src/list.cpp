#include "list.h"

template <typename T, typename Allocator>
mystd::list<T, Allocator>::list() {
  head = block_elem_ptr;
  size = 0;
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
      AllocTraits::construct(alloc, ptr++, *it, ptr);
    }

    // --ptr;
    ptr = block_elem_ptr;
  }
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::list(list<value_type, allocator_type>&& rhs) noexcept : block_elem_ptr(nullptr)  {
  alloc = std::move(rhs.alloc);

  head = rhs.head;
  rhs.head = nullptr;

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
  AllocTraits::deallocate(alloc, block_elem_ptr, 1);

  alloc = std::move(rhs.alloc);

  head = rhs.head;
  rhs.head = nullptr;

  block_elem_ptr = rhs.block_elem_ptr;
  rhs.block_elem_ptr = nullptr;

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

  auto it_rhs = rhs.cbegin();
  for (auto it = cbegin(); it != cend(); ++it) {
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
  return size > 0 ? false : true;
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
void mystd::list<T, Allocator>::insert_after(const_reference obj, const iterator& it) {
  if (size == 0) {
    push_front(obj);
    return;
  }
  
  mystd::list<T, Allocator>::iterator iter = this->begin();
  for (; iter != it; ++iter) {}

  Node* temp = iter.get_ptr()->next;
  iter.get_ptr()->next = AllocTraits::allocate(alloc, 1);
  AllocTraits::construct(alloc, iter.get_ptr()->next, obj, temp);
  ++size;
}

template <typename T, typename Allocator>
void mystd::list<T, Allocator>::erase_after(const iterator& it) {
  if (size == 0) {
    throw std::range_error("List is empty");
  }

  if (it + 1 == end()) {
    throw std::range_error("Erase after last element");
  }

  // mystd::list<T, Allocator>::iterator iter = this->begin();
  // for (; iter != it; ++iter) {}

  Node* temp = it.get_ptr()->next->next;

  AllocTraits::destroy(alloc, it.get_ptr()->next);
  AllocTraits::deallocate(alloc, it.get_ptr()->next, 1);

  it.get_ptr()->next = temp;
  --size;
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
  if (this->ptr != nullptr) {
    return this->ptr->obj;
  }
  
  throw std::runtime_error("dereferencing of invalid iterator");
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::const_reference mystd::list<T, Allocator>::iterator::operator*() const {
  return this->ptr->obj;
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator::pointer mystd::list<T, Allocator>::iterator::operator->() {
  return &this->ptr->obj;
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator::pointer mystd::list<T, Allocator>::iterator::operator->() const {
  return &this->ptr->obj;
}

template <typename T, typename Allocator>
bool mystd::list<T, Allocator>::iterator::operator==(const iterator& rhs) const {
  return ptr == rhs.ptr ? true : false;
}

template <typename T, typename Allocator>
bool mystd::list<T, Allocator>::iterator::operator!=(const iterator& rhs) const {
  return !(*this == rhs);
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::Node* mystd::list<T, Allocator>::iterator::get_ptr() const {
  return ptr;
}
