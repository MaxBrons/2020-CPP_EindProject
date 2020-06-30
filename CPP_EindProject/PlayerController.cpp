#include "PlayerController.h"
#include <ioStream>

PlayerController::PlayerController(Entity* player)
	:_player(player)
{
}

PlayerController::~PlayerController()
{
}

void PlayerController::Update(float dt, Object* obj)
{
	if (_player == nullptr) return;
	sf::Vector2f vec(0, 0);
	if (_player->GetPosition().y < obj->GetPos().y - 10) _player->UpdatePosition(sf::Vector2f(0, .1), dt);
	else if (_jumped) _jumped = false;


	//Vertical movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (_player->GetPosition().y < obj->GetPos().y - 10 || _jumped) return;
		_jumped = true;
		_player->UpdatePosition(sf::Vector2f(0,-100), dt);
		return;
	}

	//Horizontal movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (_player->GetPosition().x + 1) <= 1920 - 25) vec.x += 1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (_player->GetPosition().x - 1) >= 25) vec.x -= 1;
	if(vec != sf::Vector2f(0,0)) _player->UpdatePosition(vec, dt);
}

void PlayerController::SetPlayer(Entity* player)
{
	_player = player;
}