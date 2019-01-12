#include "stdcxx/LiteMutableBuffer.h"

bool LiteMutableBuffer::initWithCapacity(size_t in_capacity) {
  buffer_ = (byte *)lite_alloc(in_capacity);
  if (!buffer_) {
    FAFAL_CHECK(buffer_);
    return false;
  }

  length_   = 0;
  cursor_   = buffer_;
  capacity_ = in_capacity;
  return true;
}

size_t LiteMutableBuffer::getLength() { return length_; }

size_t LiteMutableBuffer::getCapacity() { return capacity_; }

size_t LiteMutableBuffer::ensureCapacity(size_t new_capacity) {
  byte *new_buffer;
  unsigned int final_capacity;

  if (new_capacity <= capacity_)
    return capacity;
  final_capacity = ALIGN(new_capacity, 8);

  new_buffer = (byte *)lite_alloc(final_capacity);

  if (new_buffer) {
    buffer_   = new_buffer;
    capacity_ = new_capacity;
    cursor_   = buffer_ + length_;
  }

  return capacity_;
}