//
// Created by lumadev on 28/08/2025.
//

#pragma once


struct SDL_Window;
struct SDL_Renderer;

inline struct Context {
	SDL_Window* window = nullptr;
	SDL_Renderer* renderer = nullptr;
} globalContext;
