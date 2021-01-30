#ifndef ED_HPP
#define ED_HPP
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <SFML/System.hpp>
using namespace std;
class ED {
  public:
    ED(string string1, string string2);
    int penalty(char a, char b);
    int min(int a, int b, int c);
    int OptDistance();
    string Alignment();
  private:
    string string1, string2;
    vector<vector<int>> matrix;
};
#endif
