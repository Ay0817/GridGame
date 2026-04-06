#pragma once

#include <tuple>

namespace Game
{
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

		/// @brief グリッド全体の左上の座標を取得
		/// @param gridSize グリッドのサイズ
		/// @return 左上のスクリーン座標
		[[nodiscard]]
		std::pair<int, int> GetStart(int gridSize) const {
			auto sx = cx - (gridSize * cellSize) / 2;
			auto sy = cy - (gridSize * cellSize) / 2;

			return { sx,sy };
		}

		/// @brief スクリーン座標からグリッド座標に変換
		/// @param mx マウス x座標
		/// @param my マウス y座標
		/// @param gridSize グリッドのサイズ
		/// @return セル座標
		[[nodiscard]]
		std::pair<int, int> ScreenToGrid(int mx, int my, int gridSize) const {
			auto [sx, sy] = GetStart(gridSize);

			auto gx = (mx - sx) / cellSize;
			auto gy = (my - sy) / cellSize;

			return { gx,gy };
		}

		/// @brief 指定セル座標をスクリーン座標に変換
		/// @param gx セル x座標
		/// @param gy セル y座標
		/// @param gridSize グリッドのサイズ
		/// @return スクリーン座標
		[[nodiscard]]
		std::pair<int, int> GridToScreen(int gx, int gy, int gridSize) const {
			auto [sx, sy] = GetStart(gridSize);

			auto x = sx + gx * cellSize;
			auto y = sy + gy * cellSize;

			return { x, y };
		}

		/// @brief マウス座標がグリッド内か判定
		/// @param mx マウス x座標
		/// @param my マウス y座標
		/// @param gridSize グリッドのサイズ
		/// @return true なら グリッド内, false ならグリッド外
		[[nodiscard]]
		bool IsInside(int mx, int my, int gridSize) const {
			auto [startX, startY] = GetStart(gridSize);

			return mx >= startX && mx < startX + gridSize * cellSize && my >= startY && my < startY + gridSize * cellSize;
		}
	};
}
