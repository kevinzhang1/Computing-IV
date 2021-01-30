#include "ED.hpp"
int main(int argc, const char* argv[]) {
  sf::Clock clock;
  sf::Time t;
  string string1, string2;
  cin>>string1>>string2;
  ED ed(string1, string2);
  auto f1=[](int x) {return x;};
  cout<<"Edit distance = "<<f1(ed.OptDistance())<<"\n";
  cout<<ed.Alignment();
  t=clock.getElapsedTime();
  cout<<"\nExecution time is "<<t.asSeconds()<<" seconds \n";
  return 0;
}
