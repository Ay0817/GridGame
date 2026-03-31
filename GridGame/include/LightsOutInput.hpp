#pragma once

#include "Component.hpp"
#include "Grid.hpp"
#include "GridConfig.hpp"
#include "Audio.hpp"

/// @brief グリッドへの入力処理を行う
class LightsOutInput final : public Component {
private:
	Grid* _grid = nullptr;   // 操作対象へのポインタ
	GridConfig _gridConfig;  // グリッドの構成
	AudioPlay _clickSound;   // クリックしたときのサウンド
public:
	/// @brief コンストラクタ
	/// @param config グリッドの構成
	LightsOutInput(const GridConfig& config);

	/// @brief 初期化処理
	virtual void Begin() override;

	/// @brief 更新処理
	virtual void Update() override;
};
