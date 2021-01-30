#include <SFML/Graphics.hpp>
#include "PTree.hpp"
using namespace std;

int main(int argc, char *argv[]) {
  sf::RenderWindow window(sf::VideoMode(6*stoi(argv[1]), 4*stoi(argv[1])), "Window");
  PTree tree(stoi(argv[1]), stoi(argv[2]));
  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type==sf::Event::Closed) {
	window.close();
      }
    }
    window.clear();
    window.draw(tree);
    window.display();
  }
}
