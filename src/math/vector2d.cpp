//
// Created by lumadev on 01/09/2025.
//

#include "vector2d.h"

#include <cmath>

namespace Math
{
	Vector2D Vector2D::operator+=(const Vector2D other) const
	{
		return *this + other;
	}

	Vector2D Vector2D::operator-=(const Vector2D other) const
	{
		return *this - other;
	}

	Vector2D Vector2D::operator*=(const float scale) const
	{
		return *this * scale;
	}

	Vector2D Vector2D::operator/=(const float scale) const
	{
		return *this / scale;
	}

	Vector2D Vector2D::Normalize()
	{
		const float length = std::sqrtf(this->x * this->x + this->y * this->y);
		if (length != 0.f)
		{
			this->x = this->x / length;
			this->y = this->y / length;
		}

		return *this;
	}

	float Vector2D::DotProduct(const Vector2D other) const
	{
		return this->x * other.x + this->y * other.y;
	}

	Vector2D operator+(Vector2D vector, const Vector2D other)
	{
		vector.x += other.x;
		vector.y += other.y;

		return vector;
	}

	Vector2D operator-(Vector2D vector, const Vector2D other)
	{
		vector.x -= other.x;
		vector.y -= other.y;
		return vector;
	}

	Vector2D operator*(Vector2D vector, const float scale)
	{
		vector.x *= scale;
		vector.y *= scale;

		return vector;
	}

	Vector2D operator/(Vector2D vector, const float scale)
	{
		vector.x /= scale;
		vector.y /= scale;

		return vector;
	}
}
