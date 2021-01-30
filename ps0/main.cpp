#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(20000, 20000), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
        sf::Texture texture;
    if (!texture.loadFromFile("sprite.png"))
        return EXIT_FAILURE;
    sf::Sprite sprite(texture);
    sprite.setPosition(1.f, 1.f);
    sprite.setScale(1.f, 1.f);
    int i=0;
    int ii=0;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
	  switch(event.type) {
	    case sf::Event::KeyPressed:
	      if(i==0) {
	    sprite.setPosition(50.f, 50.f);
	    i=1;
	      } else {
		sprite.setPosition(1.f, 1.f);
		i=0;
	      }
	    break;
	  default:
	    break;
	  }
	  if(event.type==sf::Event::MouseWheelScrolled) {
	    if(ii==0) {
	      sprite.setScale(2.f, 2.f);
	      ii=1;
		} else {
	      sprite.setScale(1.f, 1.f);
	      ii=0;
	    }

	  }
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
	window.draw(sprite);
        window.display();
    }

    return 0;
}
