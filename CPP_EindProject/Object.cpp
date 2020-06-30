#include "Object.h"

Object::Object(sf::Vector2f size, sf::Vector2f pos, sf::Color color)
	:_size(size), _pos(pos), _color(color)
{
	_shape = new sf::RectangleShape(size);
	_shape->setFillColor(color);
	_shape->setPosition(pos);
}

Object::~Object()
{
}

void Object::draw(sf::RenderWindow* window)
{
	window->draw(*_shape);
}

sf::Vector2f Object::GetPos()
{
	return _pos;
}


