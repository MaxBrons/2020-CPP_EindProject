#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

class Object
{
public:
	Object(sf::Vector2f size, sf::Vector2f pos, sf::Color color);
	~Object();
	void draw(sf::RenderWindow* window);
	sf::Vector2f GetPos();

private:
	sf::RectangleShape* _shape;
	sf::Vector2f _size;
	sf::Vector2f _pos;
	sf::Color _color;
};

