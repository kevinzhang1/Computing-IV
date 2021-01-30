#include <stdint.h>
#include <iostream>
#include <string>
#include <sstream>
#include <exception>
#include <stdexcept>
#include <vector>
// Copyright 2020 <Kevin Zhang>
#ifndef _USR_CS_UNDERGRAD_2022_KZHANG1_PS4A_RINGBUFFER_H_
#define _USR_CS_UNDERGRAD_2022_KZHANG1_PS4A_RINGBUFFER_H_
using std::vector;
class RingBuffer {
 public:
  explicit RingBuffer(int capacity);
  int size();
  bool isEmpty();
  bool isFull();
  void enqueue(int16_t x);
  int16_t dequeue();
  int16_t peek();
 private:
  vector<int16_t> buffer;
  int capacity;
};
#endif  // _USR_CS_UNDERGRAD_2022_KZHANG1_PS4A_RINGBUFFER_H_
