//
// Created by lumadev on 01/09/2025.
//

#include "shapes.h"

namespace Math
{
	Rectangle::operator SDL_Rect() const
	{
		return {
			.x = static_cast<int>(x),
			.y = static_cast<int>(y),
			.w = static_cast<int>(width),
			.h = static_cast<int>(height)
		};
	}

	Rectangle::operator SDL_FRect() const
	{
		return {
			.x = x,
			.y = y,
			.w = width,
			.h = height
		};
	}
}
