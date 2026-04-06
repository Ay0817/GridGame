#pragma once

#include "AssetManager.hpp"

namespace Core::Resource
{
	/// @brief アセットのロードや取得を行う
	class AssetResolver final {
	public:
		/// @brief 指定した型のアセットをロードする
		/// @tparam T ロードしたいアセットの型
		/// @param name アセット名
		/// @param path ファイルパス
		/// @return 指定した型のアセット
		template <IsAsset T, class... Args>
		[[nodiscard]]
		static std::shared_ptr<T> Load(std::string_view name, std::string_view path, Args&&... args) {
			return AssetManager::Load<T>(name, path, std::forward<Args>(args)...);
		}

		/// @brief 指定した型のアセットを取得
		/// @tparam T 取得したいアセットの型
		/// @param name アセット名
		/// @return 指定した型のアセット
		template <IsAsset T>
		[[nodiscard]]
		static std::shared_ptr<T> Get(std::string_view name) {
			return AssetManager::Get<T>(name);
		}
	};
}
