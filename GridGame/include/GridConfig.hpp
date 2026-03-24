#pragma once

/// @brief グリッドの構成
struct GridConfig {
	int cellSize; // セルのサイズ
	int cx;       // 中央 x座標
	int cy;       // 中央 y座標

	/// @brief コンストラクタ 
	/// @param cellSize セルのサイズ
	/// @param cx 中央 x座標
	/// @param cy 中央 y座標
	GridConfig(int cellSize, int cx, int cy)
		: cellSize(cellSize)
		, cx(cx)
		, cy(cy)
	{}
};
