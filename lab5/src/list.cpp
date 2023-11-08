#include "list.h"

template <typename T, typename Allocator>
mystd::list<T, Allocator>::list(std::initializer_list<value_type>& lst) {
  // TODO
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::list(const allocator_type& alloc): alloc(alloc) {}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::list(const list<value_type, allocator_type>& rhs): alloc(rhs.alloc), block_elem_ptr(AllocTraits::allocate(alloc, 1)), before_begin_ptr(AllocTraits::allocate(alloc, 1)) {
 // TODO
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::list(list<value_type, allocator_type>&& rhs) noexcept {
  alloc = std::move(rhs.alloc);

  head = rhs.head;
  rhs.head = nullptr;

  block_elem_ptr = AllocTraits::allocate(alloc, 1);
  before_begin_ptr = AllocTraits::allocate(alloc, 1);

  size = rhs.size;
  rhs.size = 0;
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>& mystd::list<T, Allocator>::operator=(const list<value_type, allocator_type>& rhs) {
  // TODO
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>& mystd::list<T, Allocator>::operator=(list<value_type, allocator_type>&& rhs) noexcept {
  clear();

  alloc = std::move(rhs.alloc);

  head = rhs.head;
  rhs.head = nullptr;

  size = rhs.size;
  rhs.size = 0;
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::~list() {
  std::cout << "magic" << std::endl;
  // TODO
}

template <typename T, typename Allocator>
bool mystd::list<T, Allocator>::operator==(const list<value_type, allocator_type>& rhs) const noexcept {
  // TODO
}

template <typename T, typename Allocator>
bool mystd::list<T, Allocator>::operator!=(const list<value_type, allocator_type>& rhs) const noexcept {
  // TODO
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
  // TODO
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::const_reference mystd::list<T, Allocator>::front() const {
  // TODO
}

template <typename T, typename Allocator>
void mystd::list<T, Allocator>::clear() {
  // TODO
}

template <typename T, typename Allocator>
void mystd::list<T, Allocator>::push_back(const_reference obj) {
  // TODO
}

template <typename T, typename Allocator>
void mystd::list<T, Allocator>::push_front(const_reference obj) {
  // TODO
}

template <typename T, typename Allocator>
void mystd::list<T, Allocator>::pop_back() {
  // TODO
}

template <typename T, typename Allocator>
void mystd::list<T, Allocator>::pop_front() {
  // TODO
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::reference mystd::list<T, Allocator>::operator[](size_type index) {
  // TODO
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::const_reference mystd::list<T, Allocator>::operator[](size_type index) const {
  // TODO
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::before_begin() {
  // TODO
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::cbefore_begin() const {
  // TODO
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::begin() {
  // TODO
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::cbegin() const {
  // TODO
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::end() {
  // TODO
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::cend() const {
  // TODO
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::Node::Node(const T& value) {
  // TODO
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::Node::Node(const T& value, Node* next) {
  // TODO
}

template <typename T, typename Allocator>
mystd::list<T, Allocator>::iterator::iterator(Node* ptr) {
  // TODO
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator& mystd::list<T, Allocator>::iterator::operator++() {
  // TODO
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator& mystd::list<T, Allocator>::iterator::operator++() const {
  // TODO
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator& mystd::list<T, Allocator>::iterator::operator+=(size_t rhs) {
  // TODO
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator& mystd::list<T, Allocator>::iterator::operator+=(size_t rhs) const {
  // TODO
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator mystd::list<T, Allocator>::iterator::operator+(size_t rhs) const {
  // TODO
}

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator::reference mystd::list<T, Allocator>::iterator::operator*() {
  // TODO
}

// template <typename T, typename Allocator>
// const typename mystd::list<T, Allocator>::iterator::reference mystd::list<T, Allocator>::iterator::operator*() const {
//   // TODO
// }

template <typename T, typename Allocator>
typename mystd::list<T, Allocator>::iterator::pointer mystd::list<T, Allocator>::iterator::operator->() {
  // TODO
}

template <typename T, typename Allocator>
const typename mystd::list<T, Allocator>::iterator::pointer mystd::list<T, Allocator>::iterator::operator->() const {
  // TODO
}

