#include "/usr/cs/undergrad/2022/kzhang1/ps4a/RingBuffer.h"
#include <string>
using std::invalid_argument;
using std::runtime_error;
using std::string;
// Copyright 2020 <Kevin Zhang>
RingBuffer::RingBuffer(int capacity) {
  string error = "RingBuffer constructor: capacity must be greater than zero.";
  if (capacity < 1)
    throw invalid_argument(error);
  this->capacity = capacity;
}
int RingBuffer::size() {
  return buffer.size();
}
bool RingBuffer::isEmpty() {
  if (buffer.size() == 0) {
    return true;
  } else {
    return false;
  }
}
bool RingBuffer::isFull() {
  if ((signed)buffer.size() == capacity)
    return true;
  else
    return false;
}
void RingBuffer::enqueue(int16_t x) {
  if ((signed)buffer.size() == capacity)
    throw runtime_error("enqueue: can't enqueue to a full ring.");
  auto push = [&](int a) {
    buffer.push_back(a);
  };
  push(x);
}
int16_t RingBuffer::dequeue() {
  if (isEmpty())
    throw runtime_error("dequeue: can't dequeue to an empty ring.");
  int16_t element = buffer.front();
  auto erase = [&]() {
    buffer.erase(buffer.begin());
  };
  erase();
  return element;
}
int16_t RingBuffer::peek() {
  if (isEmpty())
    throw runtime_error("peek: can't peek to an empty ring.");
  return buffer.front();
}
