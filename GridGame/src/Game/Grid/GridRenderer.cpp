#include <DxLib.h>
#include <cassert>

#include "../../../include/GameObject.hpp"
#include "../../../include/GridRenderer.hpp"

GridRenderer::GridRenderer(const GridConfig& config)
	: Component()
	, _gridConfig(config)
	, _lineColor(Color(0, 0, 0, 255))
	, _offColor(Color(255, 255, 255, 255))
	, _onColor(Color(180, 241, 249, 255))
{}

void GridRenderer::DrawCells(const Grid& grid, int startX, int startY) const {
	auto size = grid.GetSize();

	for (int y = 0; y < size; ++y) {
		for (int x = 0; x < size; ++x) {

			auto left = startX + x * _gridConfig.cellSize;
			auto top = startY + y * _gridConfig.cellSize;
			auto color = grid.GetCell(x, y) ? _onColor : _offColor;

			DrawBox(left, top, left + _gridConfig.cellSize, top + _gridConfig.cellSize, color.ToRGB(), TRUE);
		}
	}
}

void GridRenderer::DrawGridLines(int gridSize, int startX, int startY) const {
	// cü
	for (int x = 0; x <= gridSize; ++x) {
		auto posX = startX + x * _gridConfig.cellSize;

		DrawLine(posX, startY, posX, startY + gridSize * _gridConfig.cellSize, _lineColor.ToRGB());
	}

	// ‰¡ü
	for (int y = 0; y <= gridSize; ++y) {
		auto posY = startY + y * _gridConfig.cellSize;

		DrawLine(startX, posY, startX + gridSize * _gridConfig.cellSize, posY, _lineColor.ToRGB());
	}
}

void GridRenderer::Begin() {
	auto owner = GetOwner();

	_grid = owner->GetComponent<Grid>();

	assert(_grid != nullptr);
}

void GridRenderer::Draw() const {
	auto size = _grid->GetSize();
	auto sx = _gridConfig.cx - (size * _gridConfig.cellSize) / 2;
	auto sy = _gridConfig.cy - (size * _gridConfig.cellSize) / 2;

	DrawCells(*_grid, sx, sy);
	DrawGridLines(size, sx, sy);
}
