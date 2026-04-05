//
// Created by lumadev on 28/08/2025.
//

#include "timing.h"

#include <SDL3/SDL.h>

Uint64 startTime = SDL_GetTicks();
float deltaTime = 0.0f;

void Time::Initialize()
{
	startTime = SDL_GetTicks();
}

void Time::Update()
{
	const Uint64 endTime = SDL_GetTicks();
	deltaTime = static_cast<float>(endTime - startTime) / 1000.0f;
	startTime = endTime;
}

float Time::GetDeltaTime()
{
	return deltaTime;
}
