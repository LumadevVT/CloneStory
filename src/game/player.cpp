//
// Created by lumadev on 01/09/2025.
//

#include "player.h"

#include <X11/Xproto.h>

#include "../input/input.h"
#include "../time/timing.h"

SDL_FRect srcRect = {0.f, 0.f, 16.f, 16.f};

Player::Player() :
	sprite("assets/quote.png", srcRect, 4, 11, 8)
{
	sprite.RegisterAnimation("idle_left", {0});
	sprite.RegisterAnimation("idle_right", {11 + 0});
	sprite.RegisterAnimation("run_left", {0, 1, 0, 2});
	sprite.RegisterAnimation("run_right", {11 + 0, 11 + 1, 11 + 0, 11 + 2});

	sprite.PlayAnimation("idle_left");
}

//
// // NO LINT BECAUSE DESTRUCTOR IS BEING DELETED
// // THIS IS BULLSHIT.
// Player::~Player() // NOLINT(*-use-equals-default)
// {
// }

void Player::Update()
{
	sprite.Update();

	int direction = 0.f;
	if (Input::Keyboard::IsKeyHeld(SDL_SCANCODE_LEFT))
	{
		direction -= 1;
	}
	if (Input::Keyboard::IsKeyHeld(SDL_SCANCODE_RIGHT))
	{
		direction += 1;
	}

	lastDirection = direction != 0 ? static_cast<Direction>(direction) : lastDirection;

	if (lastDirection == Direction::LEFT)
	{
		sprite.PlayAnimation(direction != 0 ? "run_left" : "idle_left");
	}
	else
	{
		sprite.PlayAnimation(direction != 0 ? "run_right" : "idle_right");
	}
	position.x += 120.f * Time::GetDeltaTime() * static_cast<float>(direction);
}

void Player::Render() const
{
	sprite.Render(position, 2.f);
}
