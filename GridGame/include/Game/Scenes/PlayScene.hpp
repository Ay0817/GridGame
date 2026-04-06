#pragma once

#include "Core/Scene.hpp"
#include "Game/Grid/GridConfig.hpp"

namespace Game
{
	/// @brief プレイシーン
	class PlayScene final : public Core::Scene {
	private:
		GridConfig _gridConfig; // グリッドの構成
	public:
		/// @brief コンストラクタ
		/// @param name シーン名
		PlayScene(const std::string& name);

		/// @brief 初期化処理
		virtual void Begin() override;
	};
}
