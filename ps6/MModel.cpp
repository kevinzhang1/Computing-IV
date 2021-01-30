// Copyright 2020 <Kevin Zhang>
#include <utility>
#include <map>
#include <string>
#include "MModel.h"
MModel::MModel(string text, int k) {
  srand(time(NULL));
  this->k = k;
  string texts = text;
  for (int i = 0; i < k; i++)
    texts.push_back(text[i]);
  for (auto i : text)
    if (ch.find(i) == string::npos)
      ch.push_back(i);
  for (int i = 0; i < 2; i++)
    for (int ii = 0; ii < (signed)text.length(); ii++)
      kgrams.insert(pair<string, int>(texts.substr(ii, k+i), 0));
  for (int i = 0; i < 2; i++)
    for (int ii = 0; ii < (signed)text.length(); ii++) {
      map<string, int>::iterator itr = kgrams.find(texts.substr(ii, k+i));
      kgrams[texts.substr(ii, k+i)] = itr->second+1;
    }
}

int MModel::kOrder() {
  return k;
}

int MModel::freq(string kgram) {
  if (kgram.length() != (unsigned)k)
    throw runtime_error("k-gram must be of length k.");
  map<string, int>::iterator itr = kgrams.find(kgram);
  if (itr == kgrams.end())
    return 0;
  return itr->second;
}

int MModel::freq(string kgram, char c) {
  if (kgram.length() != (unsigned)k)
    throw runtime_error("k-gram must be of length k.");
  kgram.push_back(c);
  map<string, int>::iterator itr = kgrams.find(kgram);
  if (itr == kgrams.end())
    return 0;
  return itr->second;
}
char MModel::kRand(string kgram) {
  if (kgram.length() != (unsigned)k)
    throw runtime_error("kgram must be of length k.");
  map<string, int>::iterator itr = kgrams.find(kgram);
  if (itr == kgrams.end())
    throw runtime_error("The given kgram could not be found.");
  int r = rand()%freq(kgram); //NOLINT
  double x = 0;
  for (auto a : ch) {
    if((double)r/freq(kgram) < (double)freq(kgram, a)/freq(kgram)+x&&(double)freq(kgram, a)/freq(kgram) != 0) //NOLINT
      return a;
    x+=(double)freq(kgram, a)/freq(kgram); //NOLINT
  }
  return '-';
}
string MModel::generate(string kgram, int T) {
  if (kgram.length() != (unsigned)k)
    throw runtime_error("k-gram must be of length k.");
  string s = kgram;
  for (int a = 0; a < T-k; a++)
    s.push_back(kRand(s.substr(a, k)));
  return s;
}
ostream& operator<<(ostream &o, MModel &m) {
  o << "Order: " << m.k << endl;
  o << "Alphabet: " << m.ch << endl;
  o << "Frequencies of the k-grams and K+1-grams: " <<endl;
  map<string, int>::iterator itr;
  for (itr = m.kgrams.begin(); itr != m.kgrams.end(); itr++)
    o << itr->first << "\t" << itr->second << "\n";
  return o;
}
