#include <SFML/Graphics.hpp>
#include "FibLFSR.hpp"
using namespace std;

void transform(sf::Image& image, FibLFSR* fiblfsr) {
  sf::Vector2u s=image.getSize();
  int g=*fiblfsr.generate(8);
  sf::Color c;
  for(int x=0;x<s.x;x++) {
    for(int y=0;x<s.y;y++) {
      c=image.getPixel(x, y);
      c.r=c.r^g;
      c.g=c.g^g;
      c.b=c.b^g;
      image.setPixel(x, y, c);
    }
  }
}

int main(int argc, char* argv[])
{
  string seed = argv[3];
  sf::Image input;
  sf::Image output;
  FibLFSR fiblfsr(seed);
    if(!input.loadFromFile(argv[1])) {
	return -1;
      }
    if(!output.loadFromFile(argv[1])) {
      return -1;
    }
    transform(&output, &fiblfsr);
    sf::RenderWindow window1(sf::VideoMode(20000, 20000), "SFML works!");
    sf::RenderWindow window2(sf::VideoMode(20000, 20000), "SFML works!");
    sf::Texture itexture, otexture;
    sf::Sprite isprite(itexture), osprite(otexture);
    itexture.loadFromImage(input);
    otexture.loadFromImage(output);
    while (window1.isOpen() && window2.isOpen()) {
      sf::Event event;
      while (window1.pollEvent(event)) {
	if(event.type == sf::Event::Closed)
	  window1.close();
      }
      while (window2.pollEvent(event)) {
	if(event.type == sf::Event::Closed)
	  window2.close();
      }
      window1.clear();
      window1.draw(isprite);
      window1.display();
      window2.clear();
      window2.draw(osprite);
      window2.display();
    }
    return 0;
}
