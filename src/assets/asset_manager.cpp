//
// Created by lumadev on 01/09/2025.
//

#include "asset_manager.h"

#include <iostream>
#include <vector>

#include "globals.h"

#include <SDL3_image/SDL_image.h>

extern unsigned char texture_missing_png[];
unsigned int texture_missing_png_len;

namespace fs = std::filesystem;

// TODO Sistema de recarregamento de assets, possivelmente com callbacks.

ImageAsset Assets::LoadImage(const std::string& path) {
	SDL_Texture* texture = IMG_LoadTexture(globalContext.renderer, path.c_str());
	SDL_SetTextureScaleMode(texture, SDL_SCALEMODE_NEAREST);
	if (texture == nullptr) {
		// !TODO Embutir imagem como foto de textura sumida (2x2 da source)
		// std::cerr << "Unable to load texture: " << SDL_GetError() << std::endl;
		// SDL_Surface* surface = SDL_Create(
		// 		256,
		// 		256,
		// 		SDL_PIXELFORMAT_RGBA32,
		// 		texture_missing_png,
		// 		256 * 4
		// 		);
		//
		// texture = SDL_CreateTextureFromSurface(globalContext.renderer, surface);

		throw std::runtime_error("Unable to load texture: " + std::string(SDL_GetError()));
	}

	return {
		.asset = {
			.filePath = path,
			.lastWriteTime = fs::last_write_time(path),
		},
		.texture = texture,
	};
}
