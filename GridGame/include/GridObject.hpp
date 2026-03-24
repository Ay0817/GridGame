#pragma once

#include <memory>

#include "GameObject.hpp"
#include "Grid.hpp"
#include "Audio.hpp"

/// @brief グリッドゲーム本体
class GridObject final : public GameObject {
private:
	Grid _grid;            // グリッドのコアデータ
	AudioPlay _clearSound; // クリア時のサウンド 

	bool _isCleared = false; // クリア済みか？
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
