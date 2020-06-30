#include "Entity.h"

Entity::Entity(float x, float y, float width, float height, float speed, sf::Color color)
	:x(x), y(y), width(width), height(height), speed(speed), _color(color)
{
	_body = new sf::RectangleShape(sf::Vector2f(width, height));
	_body->setFillColor(color);
}

Entity::~Entity()
{
}

void Entity::Draw(sf::RenderWindow* window)
{
	_body->setPosition(x,y);
	window->draw(*_body);
}

sf::Vector2f Entity::GetPosition()
{
	return sf::Vector2f(x, y);
}

void Entity::UpdatePosition(sf::Vector2f pos, float dt)
{
	x += pos.x * speed * dt;
	y += pos.y * speed * dt;
}

sf::RectangleShape* Entity::GetShape()
{
	return _body;
}
