//
// Created by lumadev on 28/08/2025.
//

#ifndef CLONESTORY_ANIMATED_SPRITE_H
#define CLONESTORY_ANIMATED_SPRITE_H

#include <SDL3/SDL_render.h>

#include <vector>
#include <string>
#include <unordered_map>

#include "math/vector2d.h"

namespace Graphics
{
	class AnimatedSprite
	{
		SDL_Texture* spriteSheet = nullptr;
		SDL_FRect srcRect = {};
		std::vector<SDL_FRect> frames = {};
		std::unordered_map<std::string, std::vector<int>> animations = {};

		int animationFPS = 16;
		std::string currentAnimation;
		std::vector<int> currentFrames;
		size_t drawFrame = 0;

		float timer = 0.0f;

	public:
		AnimatedSprite(const char* filePath, SDL_FRect srcDimensions, int vFrames = 1, int hFrames = 1, int fps = 16);
		~AnimatedSprite();

		void RegisterAnimation(const std::string& name, std::initializer_list<int> frameIndices);
		void PlayAnimation(const std::string& name);

		void Update();
		void Render(float x, float y, float scale = 1.f) const;
		void Render(Math::Vector2D position, float scale = 1.f) const;
	};
}


#endif //CLONESTORY_ANIMATED_SPRITE_H
