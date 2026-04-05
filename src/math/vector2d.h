//
// Created by lumadev on 01/09/2025.
//

#pragma once

namespace Math
{
	struct Vector2D
	{
		float x = 0.f, y = 0.f;

		Vector2D operator +=(Vector2D other) const;
		Vector2D operator -=(Vector2D other) const;

		Vector2D operator *=(float scale) const;
		Vector2D operator /=(float scale) const;

		Vector2D Normalize();
		[[nodiscard]] float DotProduct(Vector2D other) const;
	};

	Vector2D operator +(Vector2D vector, Vector2D other);
	Vector2D operator -(Vector2D vector, Vector2D other);
	Vector2D operator *(Vector2D vector, float scale);
	Vector2D operator /(Vector2D vector, float scale);
}

