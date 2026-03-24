#pragma once

#include "Component.hpp"
#include "Grid.hpp"
#include "GridConfig.hpp"

/// @brief グリッドへの入力処理を行う
class GridInput final : public Component {
private:
	Grid* _grid = nullptr;  // 操作対象へのポインタ
	GridConfig _gridConfig; // グリッドの構成

	int _prevMouse = 0; // グリッドへの入力処理を担当
	int _clickSE = -1;  // 効果音のハンドル
public:
	/// @brief コンストラクタ
	/// @param config グリッドの構成
	GridInput(const GridConfig& config);

	/// @brief 初期化処理
	virtual void Begin() override;

	/// @brief 更新処理
	virtual void Update() override;
};
