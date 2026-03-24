#pragma once

#include "GameObject.hpp"
#include "Grid.hpp"

/// @brief グリッドゲーム本体
class GridObject final : public GameObject {
private:
	Grid _grid; // グリッドのコアデータ

	bool _isCleared = false; // クリア済みか？
	int _clearSE = -1;       // 効果音ハンドル
public:
	/// @brief コンストラクタ
	/// @param name オブジェクト名
	/// @param size グリッドのサイズ
	GridObject(const std::string& name, int size);

	/// @brief 初期化処理
	virtual void Begin() override;

	/// @brief 更新処理
	virtual void Update() override;

	/// @brief グリッドのコアデータを取得
	/// @return グリッドへの参照
	Grid& GetGrid() {
		return _grid;
	}
};
