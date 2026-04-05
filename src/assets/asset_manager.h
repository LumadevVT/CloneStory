//
// Created by lumadev on 01/09/2025.
//

#pragma once

#include <string>
#include <filesystem>

#include "asset.h"

using LastWriteTime = std::filesystem::file_time_type;

namespace Assets {
	ImageAsset LoadImage(const std::string& path);
}

