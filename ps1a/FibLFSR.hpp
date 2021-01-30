#ifndef FIBLFSR
#define FIBLFSR
#include <iostream>
#include <string>
class FibLFSR {
public:
  FibLFSR(std::string seeds);

  int step();

  int generate(int k);

private:
  std::string seed;
};
#endif
