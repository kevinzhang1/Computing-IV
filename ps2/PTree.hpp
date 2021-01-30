#ifndef PTREE
#define PTREE
#include <iostream>
#include <SFML/Graphics.hpp>
#include <math.h>
class PTree:public sf::Drawable, sf::Transformable {
  public:
  PTree(int L, int N);
  void ptree(std::vector<sf::RectangleShape>& vector, sf::RectangleShape shape, int N);
private:
  std::vector<sf::RectangleShape> vec;
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif
