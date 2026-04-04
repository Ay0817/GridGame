#pragma once

#include "Component.hpp"
#include "Color.hpp"
#include "Text.hpp"

/// @brief タイトルテキストアニメーション
class TitlePromptAnimation final : public Component {
private:
	float _timer = 0.f;    // タイマー
	Color _color;          // テキストの色
	Text* _text = nullptr; // Text Component へのポインタ
public:
	/// @brief コンストラクタ
	TitlePromptAnimation();

	/// @brief 初期化処理
	virtual void Begin() override;

	/// @brief 更新処理
	virtual void Update() override;
};
