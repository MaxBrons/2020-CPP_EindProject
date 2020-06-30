#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Renderer.h"

class Entity
{
public:
    Entity(float x, float y, float width, float height,float speed, sf::Color color);
    ~Entity();
    void Draw(sf::RenderWindow* window);
    sf::Vector2f GetPosition();
    void UpdatePosition(sf::Vector2f pos);
    sf::RectangleShape* GetShape();

private:
    sf::RectangleShape* _body;
    sf::Color _color;
    float x;
    float y;
    float width;
    float height;
    float speed;
};

