#include "FibLFSR.hpp"
#include <math.h>
using namespace std;
FibLFSR::FibLFSR(string seeds) {
  seed=seeds;
}
int FibLFSR::step() {
  int p10=(int)seed.at(seed.length()-11)-48;
  int p12=(int)seed.at(seed.length()-13)-48;
  int p13=(int)seed.at(seed.length()-14)-48;
  int pmax=(int)seed.at(0);
  for(int i=0;i<(signed)seed.length()-1;i++) {
    seed[i]=seed[i+1];
  }
  seed[seed.length()-1]=((pmax^p13)^p12)^p10;
  return (int)seed[seed.length()-1]-48;
}
int FibLFSR::generate(int k) {
  int extract=0;
  for(int i=k-1;i>=0;i--) {
    int s = step();
    if(s==1) {
    extract+=pow(2, s*i);
    }
  }
  return extract;
}
