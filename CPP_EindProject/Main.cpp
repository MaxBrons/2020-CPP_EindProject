#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <vector>
#include "Renderer.h"
#include "Entity.h"
#include "PlayerController.h"
#include "Object.h"

int main()
{
	Renderer* _renderer = new Renderer(1920, 1080, "Game");
	Entity* _player = new Entity(50, 700, 50, 50, 5, sf::Color::Green);
	PlayerController* _controller = new PlayerController(_player);
	sf::RenderWindow window(_renderer->GetVideo(), _renderer->GetText());

	//static shapes in scene
	std::vector<Object*> objs;
	sf::Vector2f* startpos = new sf::Vector2f(0, 750);
	sf::Color col = sf::Color::Red;
	float objectWidth = 50;
	for (int i = 0; i < window.getSize().x / objectWidth; i++)
	{
		if (col == sf::Color::Red) col = sf::Color::Blue;
		else col = sf::Color::Red;
		Object* obj = new Object(sf::Vector2f(50, 50), sf::Vector2f(i * objectWidth, startpos->y), col);
		objs.push_back(obj);
	}

	while (window.isOpen()) {

		//deltatime = dttime.restart().asSeconds() * 100;

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//Clears the window
		window.clear();

		for (Object* o : objs) o->draw(&window);
		_player->Draw(&window);
		_controller->Update(objs[0]);

		//Displays the screen
		window.display();
	}
	return 0;
}