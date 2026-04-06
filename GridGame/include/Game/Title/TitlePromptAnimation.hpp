#pragma once

#include "Core/Component.hpp"
#include "AyLib/Color.hpp"
#include "Core/UI/Text.hpp"

namespace Game
{
	using namespace Core;

	/// @brief タイトルテキストアニメーション
	class TitlePromptAnimation final : public Component {
	private:
		float _timer = 0.f;    // タイマー
		AyLib::Color _color;          // テキストの色
		UI::Text* _text = nullptr; // Text Component へのポインタ
	public:
		/// @brief コンストラクタ
		TitlePromptAnimation();

		/// @brief 初期化処理
		virtual void Begin() override;

		/// @brief 更新処理
		virtual void Update() override;
	};
}
