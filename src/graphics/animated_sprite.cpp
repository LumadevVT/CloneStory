//
// Created by lumadev on 28/08/2025.
//

#include "animated_sprite.h"
#include "time/timing.h"

#include "globals.h"

#include <SDL3_image/SDL_image.h>

#include <iostream>
#include <ostream>

namespace Graphics
{
	AnimatedSprite::AnimatedSprite(
		const char* filePath,
		const SDL_FRect srcDimensions,
		const int vFrames, const int hFrames,
		const int fps
	) : srcRect(srcDimensions)
	{
		spriteSheet = IMG_LoadTexture(globalContext.renderer, filePath);
		SDL_SetTextureScaleMode(spriteSheet, SDL_SCALEMODE_NEAREST);
		if (spriteSheet == nullptr)
		{
			throw std::runtime_error("Unable to load texture: " + std::string(SDL_GetError()));
		}

		frames.reserve(vFrames * hFrames);
		animationFPS = fps;

		for (size_t i = 0; i < vFrames; i++)
		{
			for (size_t j = 0; j < hFrames; j++)
			{
				SDL_FRect& frame = frames.emplace_back();
				frame.x = srcDimensions.x + srcDimensions.w * static_cast<float>(j);
				frame.y = srcDimensions.y + srcDimensions.h * static_cast<float>(i);
				frame.w = srcDimensions.w;
				frame.h = srcDimensions.h;
			}
		}
	}

	AnimatedSprite::~AnimatedSprite()
	{
		SDL_DestroyTexture(spriteSheet);
	}

	void AnimatedSprite::RegisterAnimation(const std::string& name, const std::initializer_list<int> frameIndices)
	{
		animations.emplace(name, frameIndices);
	}

	void AnimatedSprite::PlayAnimation(const std::string& name)
	{
		if (!animations.contains(name))
		{
			std::cerr << "Unable to find animation: " << name << std::endl;
			return;
		}
		if (currentAnimation == name)
			return;

		drawFrame = 0;
		currentFrames = animations[name];
		currentAnimation = name;
	}

	void AnimatedSprite::Update()
	{
		timer += Time::GetDeltaTime();
		if (timer > 1.f / static_cast<float>(animationFPS))
		{
			timer = 0.0f;
			drawFrame++;
			if (drawFrame >= currentFrames.size())
				drawFrame = 0;
		}
	}

	void AnimatedSprite::Render(const float x, const float y, const float scale) const
	{
		const SDL_FRect destRect = {x, y, srcRect.w * scale, srcRect.h * scale};
		const SDL_FRect drawRect = frames[currentFrames[drawFrame]];
		SDL_RenderTexture(globalContext.renderer, spriteSheet, &drawRect, &destRect);
	}

	void AnimatedSprite::Render(const Math::Vector2D position, const float scale) const
	{
		this->Render(position.x, position.y, scale);
	}
}
