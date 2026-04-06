#pragma once

#include <string>

#include "AyLib/Rect.hpp"
#include "AyLib/Vector2.hpp"
#include "../Resource/Image.hpp"

namespace Core::UI
{
	/// @brief スプライトクラス
	class Sprite final {
	private:
		std::string _name; // スプライト名

		const Resource::Image* _image; // 画像へのポインタ
		AyLib::Rect _uv;            // 画像のどの部分を描画するかを指定する矩形
		AyLib::Vector2 _pivot;      // ピボット
	public:
		/// @brief コンストラクタ
		/// @param image スプライトに使用する画像へのポインタ
		Sprite(Resource::Image* image);

		/// @brief コンストラクタ
		/// @param image スプライトに使用する画像へのポインタ
		/// @param rect 画像のどの部分を描画するかを指定する矩形
		Sprite(Resource::Image* image, const AyLib::Rect& rect);

		/// @brief コンストラクタ
		/// @param image スプライトに使用する画像へのポインタ
		/// @param vec ピボット
		Sprite(Resource::Image* image, const AyLib::Vector2& vec);

		/// @brief コンストラクタ
		/// @param image スプライトに使用する画像へのポインタ
		/// @param rect 画像のどの部分を描画するかを指定する矩形
		/// @param vec ピボット
		Sprite(Resource::Image* image, const AyLib::Rect& rect, const AyLib::Vector2& vec);

		/// @brief UV を設定
		/// @param uv 画像のどの部分を描画するかを指定する矩形
		void SetUV(const AyLib::Rect& uv);

		/// @brief スプライト名を取得
		/// @return スプライト名
		[[nodiscard]]
		std::string GetName() const;

		/// @brief スプライトに使用する画像へのポインタを取得
		/// @return スプライトに使用する画像へのポインタ
		const Resource::Image* GetImage() const;

		/// @brief スプライトのUVを取得
		/// @return スプライトのUV
		[[nodiscard]]
		AyLib::Rect GetUV() const;

		/// @brief スプライトのピボットを取得
		/// @return スプライトのピボット
		[[nodiscard]]
		AyLib::Vector2 GetPivot() const;
	};
}
