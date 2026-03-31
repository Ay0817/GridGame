#pragma once

#include "Scene.hpp"
#include "GridConfig.hpp"

/// @brief プレイシーン
class PlayScene final : public Scene {
private:
	GridConfig _gridConfig; // グリッドの構成
public:
	/// @brief コンストラクタ
	/// @param name シーン名
	PlayScene(const std::string& name);

	/// @brief 初期化処理
	virtual void Begin() override;
};
