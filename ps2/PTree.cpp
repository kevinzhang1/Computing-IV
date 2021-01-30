#include "PTree.hpp"
using namespace std;
PTree::PTree(int L, int N) {
  sf::RectangleShape shape;
  shape.setSize(sf::Vector2f(L, L));
  shape.setPosition(2.5*L, 3*L);
  shape.setFillColor(sf::Color::Green);
  vec.push_back(shape);
  if(N>0) {
   ptree(vec, shape, N);
  }
}
void PTree::ptree(vector<sf::RectangleShape>& vec, sf::RectangleShape shape, int N) {
  sf::RectangleShape shape1, shape2;
  shape1.setSize(sf::Vector2f(shape.getSize().x/sqrt(2), shape.getSize().x/sqrt(2)));
  shape1.setFillColor(sf::Color::Green);
  shape1.setRotation(shape.getRotation()-45);
  shape2.setSize(sf::Vector2f(shape.getSize().x/sqrt(2), shape.getSize().x/sqrt(2)));
  shape2.setFillColor(sf::Color::Green);
  shape2.setRotation(shape.getRotation()+45);
  switch((int)shape.getRotation()) {
  case 0:
    shape1.setPosition(shape.getPosition().x-(shape.getSize().x/2), shape.getPosition().y-(shape.getSize().x/2));
    shape2.setPosition(shape.getPosition().x+shape.getSize().x, shape.getPosition().y-shape.getSize().x);
    break;
  case 45:
    shape1.setPosition(shape.getPosition().x, shape.getPosition().y-shape.getSize().y/sqrt(2));
    shape2.setPosition(shape.getPosition().x+sqrt(2)*shape.getSize().x, shape.getPosition().y);
    break;
  case 90:
    shape1.setPosition(shape.getPosition().x+shape.getSize().x/2, shape.getPosition().y-shape.getSize().y/2);
    shape2.setPosition(shape.getPosition().x+shape.getSize().x, shape.getPosition().y+shape.getSize().y);
    break;
  case 135:
    shape1.setPosition(shape.getPosition().x+shape.getSize().x/sqrt(2), shape.getPosition().y);
    shape2.setPosition(shape.getPosition().x, shape.getPosition().y+sqrt(2)*shape.getSize().y);
    break;
  case 180:
    shape1.setPosition(shape.getPosition().x+shape.getSize().x/2, shape.getPosition().y+shape.getSize().y/2);
    shape2.setPosition(shape.getPosition().x-shape.getSize().x, shape.getPosition().y+shape.getSize().y);
    break;
  case 225:
    shape1.setPosition(shape.getPosition().x, shape.getPosition().y+shape.getSize().y/sqrt(2));
    shape2.setPosition(shape.getPosition().x-sqrt(2)*shape.getSize().x, shape.getPosition().y);
    break;
  case 270:
    shape1.setPosition(shape.getPosition().x-shape.getSize().x/2, shape.getPosition().y+shape.getSize().y/2);
    shape2.setPosition(shape.getPosition().x-shape.getSize().x, shape.getPosition().y-shape.getSize().y);
    break;
  case 315:
    shape1.setPosition(shape.getPosition().x-shape.getSize().x/sqrt(2), shape.getPosition().y);
    shape2.setPosition(shape.getPosition().x, shape.getPosition().y-sqrt(2)*shape.getSize().y);
    break;
  default:
    shape1.setPosition(sf::Vector2f(shape.getPosition().x-(shape.getSize().x/2), shape.getPosition().y-(shape.getSize().x/2)));
    shape2.setPosition(shape.getPosition().x+shape.getSize().x, shape.getPosition().y-shape.getSize().x);
    break;
  }
  vec.push_back(shape1);
  vec.push_back(shape2);
  if(N>1) {
    ptree(vec, shape1, N-1);
    ptree(vec, shape2, N-1);
  }
}

void PTree::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  for(sf::RectangleShape i : vec) {
    target.draw(i, states);
  }
}

