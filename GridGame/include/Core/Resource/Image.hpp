#pragma once

#include "Asset.hpp"
#include "AyLib/Vector2.hpp"

namespace Core::Resource
{
	/// @brief 画像アセット
	class Image : public Asset {
	private:
		float _width;  // 画像の横幅
		float _height; // 画像の縦幅
	public:
		/// @brief コンストラクタ
		/// @param name 画像名
		/// @param path ファイルパス
		Image(const std::string& name, const std::string& path);

		/// @brief デストラクタ
		virtual ~Image();

		/// @brief 解放
		virtual void Release() override;

		/// @brief 画像の横幅を取得
		/// @return 画像の横幅
		[[nodiscard]]
		float GetWidth() const;

		/// @brief 画像の縦幅を取得
		/// @return 画像の縦幅
		[[nodiscard]]
		float GetHeight() const;

		/// @brief 画像のサイズを取得
		/// @return 画像のサイズ (横幅, 縦幅)
		[[nodiscard]]
		AyLib::Vector2 GetSize() const;
	};
}
