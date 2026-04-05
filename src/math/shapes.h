//
// Created by lumadev on 28/08/2025.
//

#pragma once

#include <SDL3/SDL_rect.h>

namespace Math
{
	struct Rectangle
	{
		float x = 0.f, y = 0.f, width = 0.f, height = 0.f;

		explicit operator SDL_Rect() const;
		explicit operator SDL_FRect() const;
	};
}
