#include <SFML/Graphics.hpp>
int main()
{	
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	//-------------------------------INITIALIZE-------------------------------
	//Create a Window
	sf::RenderWindow window(sf::VideoMode(800, 600), "MY WINDOW", sf::Style::Default, settings);
	//Create a circle
	sf::CircleShape circle(50.f);
	//Set a position
	circle.setPosition(sf::Vector2f(100, 100));
	//Put a color
	circle.setFillColor(sf::Color::Green);
	//Set an outline
	circle.setOutlineThickness(10);
	//Set a color outline
	circle.setOutlineColor(sf::Color::Blue);


	//Create a Rectangle
	sf::RectangleShape rectangle(sf::Vector2f(100, 50));
	rectangle.setPosition(sf::Vector2f(100, 100));
	rectangle.setFillColor(sf::Color::Red);
	//Set a rotation
	rectangle.setRotation(40);

	//Drawing a polygon there are more shape at the page of SFML 
	//Rhombus
	sf::CircleShape rhombus(80.0f, 4);
	rhombus.setPosition(sf::Vector2f(400,300));
	rhombus.setFillColor(sf::Color::Yellow);

	//Line
	sf::RectangleShape line(sf::Vector2f(150.f, 1.f));
	line.setPosition(sf::Vector2f(100, 200));
	line.rotate(45.f);


	//-------------------------------INITIALIZE-------------------------------

	//Run the program as long as the window is open
	while (window.isOpen())
	{

		//-------------------------------UPDATE-------------------------------
		//check all the window's events that were triggered since the last iteration of the loop
		sf::Event event;
		while (window.pollEvent(event))
		{

			//close window
			if (event.type == sf::Event::Closed)
				window.close();

		}
		//-------------------------------UPDATE--------------------------------
		

		//-------------------------------DRAW----------------------------------
		//clear the window with black color

		window.clear(sf::Color::Black);

		//Draw whatever you want
		window.draw(circle);
		window.draw(rectangle);
		window.draw(rhombus);
		window.draw(line);
		

		//end the current frame
		window.display();

		//-------------------------------DRAW----------------------------------
	}
	return 0;
}