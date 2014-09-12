#include "SFML/Graphics.hpp"
#include <iostream>

int main()
{
	sf::RenderWindow window(sf::VideoMode(600, 600), "SFML WORK!");

	sf::Texture texture;

	if (!texture.loadFromFile("Paddle Large.png"))
	{
		// handle error
	}

	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Sprite sprite2;
	sprite2.setTexture(texture);
	sprite2.setPosition(sf::Vector2f(300, 400));

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();

				break;

			}
		}

		if (sprite.getGlobalBounds().intersects(sprite2.getGlobalBounds()))
		{
			std::cout << "The sprite have collided" << std::endl;
		}
		else
		{
			sprite2.move(sf::Vector2f(0, -0.1));
		}

		window.clear();

		window.draw(sprite);
		window.draw(sprite2);

		window.display();
	}
}