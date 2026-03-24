#include "../../include/AssetManager.hpp"

std::unordered_map<int, std::shared_ptr<Asset>> AssetManager::_assets = {};

void AssetManager::End() {
	for (auto& [id, asset] : _assets) {
		asset->Release();
	}

	_assets.clear();
}
