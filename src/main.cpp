#include <iostream>
#include <vector>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "globals.h"
#include "input/input.h"
#include "time/timing.h"
#include "game/player.h"
#include "graphics/animated_sprite.h"

#define MAP_ASSETS_PATH "assets"

bool Initialize(const char* windowTitle, int width, int height);
void Shutdown();

int main(int, char**)
{
	if (!Initialize("Clone Story - Uma aventura em C++", 640, 480))
	{
		Shutdown();
		return EXIT_FAILURE;
	}

	Player quote;

	bool running = true;
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_EVENT_QUIT:
				running = false;
				break;
			default:
				break;
			}
		}

		Input::ResetState();
		Time::Update();

		quote.Update();

		SDL_SetRenderDrawColor(globalContext.renderer, 0, 0, 33, 255);
		SDL_RenderClear(globalContext.renderer);

		quote.Render();

		SDL_SetRenderDrawColor(globalContext.renderer, 255, 255, 255, 255);
		SDL_RenderDebugTextFormat(globalContext.renderer, 0, 0, "Frame time: %.3f ms", Time::GetDeltaTime() * 1000.0f);

		SDL_RenderPresent(globalContext.renderer);
	}
	Shutdown();

	return EXIT_SUCCESS;
}

bool Initialize(const char* windowTitle, const int width, const int height)
{
	if constexpr (GAME_DEBUG && SDL_PLATFORM_LINUX)
	{
		SDL_SetHint(SDL_HINT_VIDEO_X11_NET_WM_BYPASS_COMPOSITOR, "0");
	}

	constexpr SDL_InitFlags initFlags = SDL_INIT_EVENTS | SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_GAMEPAD;
	if (!SDL_Init(initFlags))
	{
		SDL_Quit();
		std::cerr << "SDL não iniciou, Erro: " << SDL_GetError() << std::endl;
		return false;
	}

	constexpr SDL_WindowFlags windowFlags = SDL_WINDOW_HIGH_PIXEL_DENSITY
		| SDL_WINDOW_RESIZABLE
		| SDL_WINDOW_HIDDEN;

	globalContext.window = SDL_CreateWindow(windowTitle, width, height, windowFlags);
	if (!globalContext.window)
	{
		std::cerr << "Erro ao criar janela: " << SDL_GetError() << std::endl;
		return false;
	}

	globalContext.renderer = SDL_CreateRenderer(globalContext.window, nullptr);
	if (!globalContext.renderer)
	{
		std::cerr << "Erro ao criar renderizador: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_SetRenderLogicalPresentation(globalContext.renderer, width, height, SDL_LOGICAL_PRESENTATION_LETTERBOX);
	SDL_SetRenderVSync(globalContext.renderer, true);

	SDL_ShowWindow(globalContext.window);

	Input::Initialize();
	Time::Initialize();

	return true;
}

void Shutdown()
{
	SDL_DestroyWindow(globalContext.window);
	SDL_DestroyRenderer(globalContext.renderer);
	SDL_Quit();
}
