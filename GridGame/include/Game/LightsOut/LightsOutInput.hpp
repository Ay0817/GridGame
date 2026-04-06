#pragma once

#include "Core/Component.hpp"
#include "Core/Audio/SoundPlayer.hpp"
#include "Game/Grid//GridData.hpp"
#include "Game/Grid/GridConfig.hpp"

namespace Game
{
	using namespace Core;

	/// @brief グリッドへの入力処理を行う
	class LightsOutInput final : public Component {
	private:
		GridData* _grid = nullptr;   // 操作対象へのポインタ
		GridConfig _gridConfig;  // グリッドの構成
		Audio::AudioPlay _clickSound;   // クリックしたときのサウンド
	public:
		/// @brief コンストラクタ
		/// @param config グリッドの構成
		LightsOutInput(const GridConfig& config);

		/// @brief 初期化処理
		virtual void Begin() override;

		/// @brief 更新処理
		virtual void Update() override;
	};
}
