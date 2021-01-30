#include "ED.hpp"
ED::ED(string string1, string string2) {
  this->string1=string1;
  this->string2=string2;
}
int ED::penalty(char a, char b) {
  if(a==b)
    return 0;
  return 1;
}
int ED::min(int a, int b, int c) {
  if(a<b&&a<c)
    return a;
  if(b<a&&b<c)
    return b;
  return c;
}
int ED::OptDistance() {
  for(int i=0; i<=(signed)string2.length(); i++) {
    vector<int> vec;
    for(int ii=0; ii<=(signed)string1.length(); ii++)
      vec.push_back(0);
    auto push = [&](vector<int> vec) {
    matrix.push_back(vec);
  };
  push(vec);
  }
  for(int i=0; i<=(signed)string1.length(); i++)
    matrix[string2.length()][i]=2*(string1.length()-i);
  for(int i=0; i<=(signed)string2.length(); i++)
    matrix[i][string1.length()]=2*(string2.length()-i);
  for(int i=string2.length()-1; i>=0; i--) {
    for(int ii=string1.length()-1; ii>=0; ii--) {
      matrix[i][ii]=min(matrix[i+1][ii+1]+penalty(string1[ii], string2[i]), matrix[i+1][ii]+2, matrix[i][ii+1]+2);
    }
  }
  return matrix[0][0];
}
string ED::Alignment() {
  ostringstream stream;
  int i=0, ii=0;
  while(i<(signed)string2.length()||ii<(signed)string1.length()) {
    if(matrix[i][ii]==matrix.at(i+1).at(ii+1)+penalty(string1[ii], string2[i])) {
      stream<<string1[ii]<<" "<<string2[i]<<" "<<penalty(string1[ii], string2[i])<<"\n";
      i++;
      ii++;
    }
    else if(matrix[i][ii]==matrix.at(i+1).at(ii)+2) {
      stream<<"- "<<string2[i]<<" 2\n";
      i++;
    }
    else if(matrix[i][ii]==matrix.at(i).at(ii+1)+2) {
      stream<<string1[ii]<<" -"<<" 2\n";
      ii++;
    }
  }
     return stream.str();
}
