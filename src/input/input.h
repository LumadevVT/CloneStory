//
// Created by lumadev on 26/08/2025.
//

#pragma once

#include <SDL3/SDL.h>

namespace Input {
	void Initialize();
	void ResetState();

	namespace Keyboard {
		bool IsKeyHeld(SDL_Scancode key);
		bool IsKeyPressed(SDL_Scancode key);
		bool IsKeyReleased(SDL_Scancode key);
	}
}
