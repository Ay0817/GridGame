#pragma once

#include <unordered_map>
#include <memory>
#include <concepts>
#include <string>
#include <string_view>

#include "Asset.hpp"
#include "Hash.hpp"

template <typename T>
concept IsAsset = std::derived_from<T, Asset>; // コンセプト

/// @brief  全アセットを管理する
class AssetManager final {
private:
	static std::unordered_map<int, std::shared_ptr<Asset>> _assets;
public:
	/// @brief 指定した型のアセットをロードする
	/// @tparam T ロードしたいアセットの型
	/// @param name アセット名
	/// @param path ファイルパス
	/// @return 指定した型のアセット
	template <IsAsset T>
	static std::shared_ptr<T> Load(std::string_view name, std::string_view path) {
		int key = Hash::FNV1a_32(name);

		auto it = _assets.find(key);

		if (it != _assets.end()) {
			return std::dynamic_pointer_cast<T>(it->second);
		}

		auto asset = std::make_shared<T>(std::string(name), std::string(path));
		_assets[key] = asset;

		return asset;
	}

	/// @brief 指定した型のアセットを取得
	/// @tparam T 取得したいアセットの型
	/// @param name アセット名
	/// @return 指定した型のアセット
	template <IsAsset T>
	static std::shared_ptr<T> Get(std::string_view name) {
		int key = Hash::FNV1a_32(name);

		auto it = _assets.find(key);

		if (it != _assets.end()) {
			return std::dynamic_pointer_cast<T>(it->second);
		}

		return nullptr;
	}

	/// @brief 終了時処理
	static void End();
};
