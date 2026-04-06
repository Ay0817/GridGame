#pragma once

#include "Core/Component.hpp"
#include "Core/Audio/SoundPlayer.hpp"
#include "Game/Grid/GridData.hpp"
#include "LightsOutPlayTimer.hpp"

namespace Game
{
	using namespace Core;

	/// @brief @brief グリッドゲーム本体
	class LightsOut final : public Component {
	private:
		Audio::AudioPlay _clearSound;       // クリア時のサウンド
		GridData* _grid = nullptr;                // グリッド
		LightsOutPlayTimer* _playTimer = nullptr; // プレイ時間を計測

		bool _isCleared = false; // クリア済みか？
	public:
		/// @brief 初期化処理
		virtual void Begin() override;

		/// @brief 更新処理
		virtual void Update() override;
	};
}
