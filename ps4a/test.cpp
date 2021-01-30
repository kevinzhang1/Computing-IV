#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include "RingBuffer.h"
// Copyright 2020 <Kevin Zhang>
using std::invalid_argument;
using std::runtime_error;
BOOST_AUTO_TEST_CASE(ringbuffer) {
  BOOST_REQUIRE_NO_THROW(RingBuffer(10));
  BOOST_REQUIRE_THROW(RingBuffer(0), invalid_argument);
  BOOST_REQUIRE_THROW(RingBuffer(-10), invalid_argument);
}
BOOST_AUTO_TEST_CASE(size) {
  RingBuffer rb(1);
  rb.enqueue(1);
  BOOST_REQUIRE(rb.size() == 1);
  rb.dequeue();
  BOOST_REQUIRE(rb.size() == 0);
}
BOOST_AUTO_TEST_CASE(isEmpty) {
  RingBuffer rb(1);
  BOOST_REQUIRE(rb.isEmpty() == true);
  rb.enqueue(1);
  BOOST_REQUIRE(rb.isEmpty() == false);
  rb.dequeue();
  BOOST_REQUIRE(rb.isEmpty() == true);
}
BOOST_AUTO_TEST_CASE(isFull) {
  RingBuffer rb(1);
  BOOST_REQUIRE(rb.isFull() == false);
  rb.enqueue(1);
  BOOST_REQUIRE(rb.isFull() == true);
  rb.dequeue();
  BOOST_REQUIRE(rb.isFull() == false);
}
BOOST_AUTO_TEST_CASE(enqueue) {
  RingBuffer rb(1);
  BOOST_REQUIRE_NO_THROW(rb.enqueue(1));
  BOOST_REQUIRE_THROW(rb.enqueue(1), runtime_error);
}
BOOST_AUTO_TEST_CASE(dequeue) {
  RingBuffer rb(1);
  rb.enqueue(1);
  BOOST_REQUIRE(rb.dequeue() == 1);
  BOOST_REQUIRE_THROW(rb.dequeue(), runtime_error);
}

BOOST_AUTO_TEST_CASE(peek) {
  RingBuffer rb(1);
  rb.enqueue(1);
  BOOST_REQUIRE(rb.peek() == 1);
  rb.dequeue();
  BOOST_REQUIRE_THROW(rb.peek(), runtime_error);
}
