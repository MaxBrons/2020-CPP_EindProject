#include "PlayerController.h"
#include <ioStream>

PlayerController::PlayerController(Entity* player)
	:_player(player)
{
}

PlayerController::~PlayerController()
{
}

void PlayerController::Update(Object* obj)
{
	if (_player == nullptr) return;
	sf::Vector2f vec(0, 0);

	if (!_jumped && _player->GetPosition().y < obj->GetPos().y - _player->GetShape()->getSize().y) _player->UpdatePosition(sf::Vector2f(0, 1.5));
	else if (_jumped && _player->GetPosition().y > obj->GetPos().y - 200) _player->UpdatePosition(sf::Vector2f(0, -1.5));
	else if (_jumped) _jumped = false;


	//Vertical movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
		if (_player->GetPosition().y > obj->GetPos().y -_player->GetShape()->getSize().y - 5 && !_jumped) {
			_jumped = true;
			vec.y -= 10;
		}
	}

	//Horizontal movement
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && (_player->GetPosition().x + 1) <= 1920 - _player->GetShape()->getSize().x) vec.x += 1;
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && (_player->GetPosition().x - 1) >= 0) vec.x -= 1;
	if (vec != sf::Vector2f(0, 0)) _player->UpdatePosition(vec);
}

void PlayerController::SetPlayer(Entity* player)
{
	_player = player;
}