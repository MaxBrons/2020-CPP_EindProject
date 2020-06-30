#include "Renderer.h"

Renderer::Renderer(float width, float height, std::string text)
	:_width(width), _height(height), _text(text)
{
}

Renderer::~Renderer()
{
}

sf::VideoMode Renderer::GetVideo()
{
	return sf::VideoMode(_width,_height);
}

std::string Renderer::GetText()
{
	return _text;
}
