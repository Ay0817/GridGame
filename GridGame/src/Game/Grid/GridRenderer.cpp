#include <DxLib.h>
#include <cassert>

#include "../../include/GridRenderer.hpp"
#include "../../include/GridObject.hpp"

GridRenderer::GridRenderer(const GridConfig& config)
	: Component()
	, _gridConfig(config)
{}

void GridRenderer::DrawCells(const Grid& grid, int startX, int startY) const {
	auto size = grid.GetSize();

	for (int y = 0; y < size; ++y) {
		for (int x = 0; x < size; ++x) {

			auto left = startX + x * _gridConfig.cellSize;
			auto top = startY + y * _gridConfig.cellSize;
			auto color = grid.GetCell(x, y) ? _onColor : _offColor;

			DrawBox(left, top, left + _gridConfig.cellSize, top + _gridConfig.cellSize, color, TRUE);
		}
	}
}

void GridRenderer::DrawGridLines(int gridSize, int startX, int startY) const {
	// cü
	for (int x = 0; x <= gridSize; ++x) {
		auto posX = startX + x * _gridConfig.cellSize;

		DrawLine(posX, startY, posX, startY + gridSize * _gridConfig.cellSize, _lineColor);
	}

	// ‰¡ü
	for (int y = 0; y <= gridSize; ++y) {
		auto posY = startY + y * _gridConfig.cellSize;

		DrawLine(startX, posY, startX + gridSize * _gridConfig.cellSize, posY, _lineColor);
	}
}

void GridRenderer::Begin() {
	auto obj = dynamic_cast<GridObject*>(GetOwner());
	_grid = &obj->GetGrid();

	assert(_grid != nullptr);

	_lineColor = GetColor(0, 0, 0);
	_offColor  = GetColor(255, 255, 255);
	_onColor   = GetColor(180, 241, 249);
}

void GridRenderer::Draw() const {
	auto size = _grid->GetSize();
	auto sx = _gridConfig.cx - (size * _gridConfig.cellSize) / 2;
	auto sy = _gridConfig.cy - (size * _gridConfig.cellSize) / 2;

	DrawCells(*_grid, sx, sy);
	DrawGridLines(size, sx, sy);
}
