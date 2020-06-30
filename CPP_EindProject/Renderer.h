#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <string>

class Renderer
{
public:
	Renderer(float width, float height,std::string text);
	~Renderer();
	sf::VideoMode GetVideo();
	std::string GetText();

private:
	float _width;
	float _height;
	sf::VideoMode _video;
	std::string _text;
};

