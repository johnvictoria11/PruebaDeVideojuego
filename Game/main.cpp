#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;

	sf::RenderWindow window(sf::VideoMode(800, 600), "VideoGame", sf::Style::Default, settings);

	// LOAD THE CHARACTER
	sf::Texture playerTexture;
	sf::Sprite playerSprite;

	if (playerTexture.loadFromFile("Assets/Player/Textures/spritesheet.png"))
	{
		std::cout << "Sprite cargado correctamente" << std::endl;
		playerSprite.setTexture(playerTexture);

		//X,Y,Widht, Height
		int xIndex = 7;
		int yIndex = 3;

		//This function select only a rectangle of the spritesheet
		playerSprite.setTextureRect(sf::IntRect(xIndex*64, yIndex*64, 64, 64));

		//This function will scale the sprite
		playerSprite.scale(sf::Vector2f(2,2));
	}

	else
	{
		std::cout << "Sprite no cargado" << std::endl;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		sf::Vector2f position = playerSprite.getPosition();

		//This code helps to move to the right the character
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			playerSprite.setPosition(position + sf::Vector2f(0.05, 0));
		}
		//This code helps to move to the left the character
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			playerSprite.setPosition(position + sf::Vector2f(-0.05, 0));
		}
		//This code helps to move down the character
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		{
			playerSprite.setPosition(position + sf::Vector2f(0, 0.05));
		}
		//This code helps to move up the character
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		{
			
			playerSprite.setPosition(position + sf::Vector2f(0, -0.05));
		}

		// Dibujar el sprite
		window.clear(sf::Color::Black);
		window.draw(playerSprite);
		window.display();
	}

	return 0;
}