//
// Created by lumadev on 26/08/2025.
//

#include "input.h"

#include <cstdlib>
#include <cstring>

bool previous_state[SDL_SCANCODE_COUNT];
const bool* current_state = nullptr;

namespace Input
{
	void Initialize()
	{
		current_state = SDL_GetKeyboardState(nullptr);
	}

	void ResetState()
	{
		std::memcpy(previous_state, current_state, SDL_SCANCODE_COUNT * sizeof(bool));
		current_state = SDL_GetKeyboardState(nullptr);
	}

	bool Keyboard::IsKeyHeld(const SDL_Scancode key)
	{
		return current_state[key];
	}

	bool Keyboard::IsKeyPressed(const SDL_Scancode key)
	{
		return current_state[key] && !previous_state[key];
	}

	bool Keyboard::IsKeyReleased(const SDL_Scancode key)
	{
		return previous_state[key] && !current_state[key];
	}
}
