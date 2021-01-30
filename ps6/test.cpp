// Copyright 2020 <Kevin Zhang>
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>
#include <iostream>
#include <string>
#include <exception>
#include <stdexcept>
#include "MModel.h"
BOOST_AUTO_TEST_CASE(test1) {
  BOOST_REQUIRE_NO_THROW(MModel("gagggagaggcgagaaa", 2));
  MModel mm("gagggagaggcgagaaa", 2);
  BOOST_REQUIRE(mm.kOrder() == 2);
  BOOST_REQUIRE(mm.freq("gg") == 3);
  BOOST_REQUIRE_THROW(mm.freq("y"), runtime_error);
  BOOST_REQUIRE(mm.freq("gg", 'g') == 1);
  BOOST_REQUIRE(mm.freq("gg", 'a') == 1);
  BOOST_REQUIRE(mm.freq("gg", 'c') == 1);
  BOOST_REQUIRE(mm.freq("gg", 'x') == 0);
}
BOOST_AUTO_TEST_CASE(test2) {
  BOOST_REQUIRE_NO_THROW(MModel("gagggagaggcgagaaa", 1));
  MModel mm("gagggagaggcgagaaa", 1);
  BOOST_REQUIRE(mm.kOrder() == 1);
  BOOST_REQUIRE_THROW(mm.freq(""), runtime_error);
  BOOST_REQUIRE_THROW(mm.freq("xy"), runtime_error);
  BOOST_REQUIRE(mm.freq("c") == 1);
  BOOST_REQUIRE(mm.freq("a", 'a') == 2);
  BOOST_REQUIRE(mm.freq("a", 'c') == 0);
  BOOST_REQUIRE(mm.freq("g", 'g') == 3);
  BOOST_REQUIRE_THROW(mm.freq(""), runtime_error);
  BOOST_REQUIRE_NO_THROW(mm.freq("y"));
  BOOST_REQUIRE_THROW(mm.freq("", 'g'), runtime_error);
  BOOST_REQUIRE_THROW(mm.freq("", 'x'), runtime_error);
  BOOST_REQUIRE_THROW(mm.freq("hwefw", 'g'), runtime_error);
  BOOST_REQUIRE_THROW(mm.kRand("j"), runtime_error);
  BOOST_REQUIRE_THROW(mm.kRand("o"), runtime_error);
  BOOST_REQUIRE_THROW(mm.kRand("tr"), runtime_error);
}

