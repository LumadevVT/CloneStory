//
// Created by lumadev on 01/09/2025.
//

#pragma once

#include "SDL3/SDL_render.h"
#include "graphics/animated_sprite.h"
#include "math/vector2d.h"

enum class Direction
{
	LEFT = -1,
	RIGHT = 1,
};

struct Player
{
	Graphics::AnimatedSprite sprite;

	Math::Vector2D position = {640.f / 2.f - 16.f / 2.f, 360.f / 2.f - 16.f / 2.f};
	Direction lastDirection = Direction::RIGHT;

	Player();
	~Player() = default;

	void Update();
	void Render() const;
};
