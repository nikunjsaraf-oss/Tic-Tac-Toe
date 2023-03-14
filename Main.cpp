#include <SFML/Graphics.hpp>
#include <iostream>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 1024

int main()
{
	sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tic Tac Toe");

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
		window.clear();

		window.display();
	}
}