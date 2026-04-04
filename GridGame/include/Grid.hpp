#pragma once

#include <vector>

#include "Component.hpp"

/// @brief グリッドデータを管理するクラス
class Grid final : public Component {
private:
	int _gridSize; // グリッドのサイズ
	bool _notRandom; // ランダムに初期化しないかどうか

	std::vector<std::vector<bool>> _cells; // 各セルの状態
public:
	/// @brief コンストラクタ
	/// @param gridSize グリッドのサイズ
	Grid(int gridSize = 3, bool notRnd = false);

	/// @brief 初期化処理
	virtual void Begin() override;

	/// @brief 指定したセルの状態を反転 on/off のトグル
	/// @param x X座標
	/// @param y Y座標
	void Toggle(int x, int y);

	/// @brief 指定セルと上下左右のセルをまとめて反転
	/// @param x 中心セルのX座標
	/// @param y 中心セルのY座標
	void ToggleAround(int x, int y);

	/// @brief 全セルが off かどうか(クリア状態か)を判定
	/// @return すべて off なら true、それ以外は false
	bool IsCleared() const;

	/// @brief 指定セルの状態を取得
	/// @param x X座標
	/// @param y Y座標
	/// @return true なら on, false なら off
	bool GetCell(int x, int y) const;

	/// @brief グリッドのサイズを取得
	/// @return グリッドのサイズ
	int GetSize() const;
};
