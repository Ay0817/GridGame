#pragma once

#include "GridData.hpp"
#include "GridConfig.hpp"
#include "Core/Component.hpp"
#include "AyLib/Color.hpp"

namespace Game
{
	/// @brief グリッドの描画を担当
	class GridRenderer final : public Core::Component {
	private:
		GridData* _grid = nullptr;  // グリッドへのポインタ
		GridConfig _gridConfig; // グリッドの構成

		AyLib::Color _lineColor; // グリッドの線の色
		AyLib::Color _offColor;  // off の時の色
		AyLib::Color _onColor;   // on の時の色
	private:
		/// @brief セルの描画
		/// @param grid 描画対象のグリッド
		/// @param startX 描画開始X座標(左上)
		/// @param startY 描画開始Y座標(左上)
		void DrawCells(const GridData& grid, int startX, int startY) const;

		/// @brief グリッド線の描画
		/// @param gridSize グリッドサイズ
		/// @param startX 描画開始X座標
		/// @param startY 描画開始Y座標
		void DrawGridLines(int gridSize, int startX, int startY) const;
	public:
		/// @brief コンストラクタ
		/// @param config グリッドの構成
		GridRenderer(const GridConfig& config);

		/// @brief 初期化処理
		virtual void Begin() override;

		/// @brief 更新処理
		virtual void Draw() const override;
	};
}
