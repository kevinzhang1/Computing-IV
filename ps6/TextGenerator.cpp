// Copyright 2020 <Kevin Zhang>
#include <string>
#include "MModel.h"
int main(int argc, const char* argv[]) {
  int k = stoi(argv[1]), t = stoi(argv[2]);
  string input = "", s;
  while (cin >> s) {
    input+=" "+s;
    s = "";
  }
  MModel mm(input, k);
  string output_string = mm.generate(input.substr(0, k), t);
  cout << "Output: ";
  for (int a = 0; a < t; a++)
    cout << output_string[a];
  cout << "\n";
  return 0;
}
