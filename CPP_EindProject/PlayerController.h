#pragma once
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "Object.h"

class PlayerController
{
public:
	PlayerController(Entity* player);
	~PlayerController();
	void Update(float dt, Object* obj);
	void SetPlayer(Entity* player);

private:
	Entity* _player;
	bool _jumped = false;
};

