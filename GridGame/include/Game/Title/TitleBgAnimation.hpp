#pragma once

#include "Core/Component.hpp"
#include "Game/Grid/GridData.hpp"

namespace Game
{
	/// @brief タイトル背景のアニメーション
	class TitleBgAnimation final : public Core::Component {
	private:
		GridData* _grid = nullptr; // グリッドデータへのポインタ

		float _timer = 0.f;      // タイマー
		float _interval = 1.75f; // セルを切り替える間隔
	public:
		/// @brief 初期化処理
		virtual void Begin() override;

		/// @brief 更新処理
		virtual void Update() override;
	};
}
