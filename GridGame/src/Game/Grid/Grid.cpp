#include "../../include/Grid.hpp"

Grid::Grid(int gridSize)
	: _gridSize(gridSize)
	, _cells(gridSize, std::vector<bool>(gridSize, false))
{}

void Grid::Toggle(int x, int y) {
	if (x < 0 || x >= _gridSize || y < 0 || y >= _gridSize) {
		return;
	}

	_cells[y][x] = !_cells[y][x];
}

void Grid::ToggleAround(int x, int y) {
	Toggle(x, y);
	Toggle(x + 1, y);
	Toggle(x - 1, y);
	Toggle(x, y + 1);
	Toggle(x, y - 1);
}

bool Grid::IsCleared() const {
	for (int y = 0; y < _gridSize; y++) {
		for (int x = 0; x < _gridSize; x++) {
			if (!_cells[y][x]) {
				return false;
			}
		}
	}
	return true;
}

bool Grid::GetCell(int x, int y) const {
	if (x < 0 || x >= _gridSize || y < 0 || y >= _gridSize) {
		return false;
	}
	return _cells[y][x];
}

int Grid::GetSize() const {
	return _gridSize;
}
