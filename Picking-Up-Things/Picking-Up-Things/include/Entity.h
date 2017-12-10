#pragma once

#include "SDL.h"

class Entity {
public:
	Entity();
	virtual ~Entity();

	virtual void Move(float dt) = 0;
	virtual void Draw(SDL_Renderer* renderer) = 0;

protected:
};
