//
// Created by lumadev on 01/09/2025.
//

#pragma once

#include <SDL3/SDL.h>
#include <filesystem>

using LastWriteTime = std::filesystem::file_time_type;

struct Asset {
	std::string filePath;
	LastWriteTime lastWriteTime;
};

struct ImageAsset {
	Asset asset;
	SDL_Texture* texture = nullptr;
};
