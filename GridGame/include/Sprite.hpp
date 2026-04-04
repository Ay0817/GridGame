#pragma once

#include <string>

#include "Rect.hpp"
#include "Image.hpp"
#include "Vector2.hpp"

/// @brief スプライトクラス
class Sprite final {
private:
	std::string _name; // スプライト名

	const Image* _image; // 画像へのポインタ
	Rect _uv;            // 画像のどの部分を描画するかを指定する矩形
	Vector2 _pivot;      // ピボット
public:
	/// @brief コンストラクタ
	/// @param image スプライトに使用する画像へのポインタ
	Sprite(Image* image);

	/// @brief コンストラクタ
	/// @param image スプライトに使用する画像へのポインタ
	/// @param rect 画像のどの部分を描画するかを指定する矩形
	Sprite(Image* image, const Rect& rect);

	/// @brief コンストラクタ
	/// @param image スプライトに使用する画像へのポインタ
	/// @param vec ピボット
	Sprite(Image* image, const Vector2& vec);

	/// @brief コンストラクタ
	/// @param image スプライトに使用する画像へのポインタ
	/// @param rect 画像のどの部分を描画するかを指定する矩形
	/// @param vec ピボット
	Sprite(Image* image, const Rect& rect, const Vector2& vec);

	/// @brief UV を設定
	/// @param uv 画像のどの部分を描画するかを指定する矩形
	void SetUV(const Rect& uv);

	/// @brief スプライト名を取得
	/// @return スプライト名
	std::string GetName() const;

	/// @brief スプライトに使用する画像へのポインタを取得
	/// @return スプライトに使用する画像へのポインタ
	const Image* GetImage() const;

	/// @brief スプライトのUVを取得
	/// @return スプライトのUV
	Rect GetUV() const;

	/// @brief スプライトのピボットを取得
	/// @return スプライトのピボット
	Vector2 GetPivot() const;
};
