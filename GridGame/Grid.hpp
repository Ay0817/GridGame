#pragma once

#include <vector>

/// @brief Lights Out 用のグリッドデータを管理するクラス
class Grid final {
private:
	int _gridSize; // グリッドのサイズ

	std::vector<std::vector<bool>> _cells; // 各セルの状態
public:
	/// @brief コンストラクタ
	/// @param gridSize グリッドのサイズ
	Grid(int gridSize = 3);

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
