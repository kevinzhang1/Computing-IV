#ifndef MMODEL_HPP
#define MMODEL_HPP
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <stdexcept>
#include <utility>
#include <map>
#include <string>
using namespace std;
class MModel {
 public:
  MModel(string text, int k);
  int kOrder();
  int freq(string kgram);
  int freq(string kgram, char c);
  char kRand(string kgram);
  string generate(string kgram, int T);
  friend ostream& operator<<(ostream &o, MModel &m);
 private:
  int k;
  map<string, int> kgrams;
  string ch;
};
#endif
