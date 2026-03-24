#pragma once

#include "Scene.hpp"
#include "Grid.hpp"
#include "GridConfig.hpp"

/// @brief サンプルシーン
class SampleScene : public Scene {
private:
	GridConfig _gridConfig; // グリッドの構成
public:
	/// @brief コンストラクタ
	/// @param name シーン名
	SampleScene(const std::string& name);

	/// @brief 初期化処理
	virtual void Begin() override;
};
