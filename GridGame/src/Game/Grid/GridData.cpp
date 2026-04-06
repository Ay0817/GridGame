#include <Game/Grid/GridData.hpp>
#include <AyLib/Random.hpp>

namespace Game
{
	GridData::GridData(int gridSize, bool notRand)
		: Core::Component()
		, _gridSize(gridSize)
		, _notRandom(notRand)
		, _cells(gridSize, std::vector<bool>(gridSize, false))
	{}

	void GridData::Begin() {
		if (!_notRandom) {
			for (int i = 0; i < _gridSize * _gridSize; ++i) {
				auto x = AyLib::Random::Range(0, _gridSize);
				auto y = AyLib::Random::Range(0, _gridSize);

				Toggle(x, y);
			}
		}
	}

	void GridData::Toggle(int x, int y) {
		if (x < 0 || x >= _gridSize || y < 0 || y >= _gridSize) {
			return;
		}

		_cells[y][x] = !_cells[y][x];
	}

	void GridData::ToggleAround(int x, int y) {
		Toggle(x, y);
		Toggle(x + 1, y);
		Toggle(x - 1, y);
		Toggle(x, y + 1);
		Toggle(x, y - 1);
	}

	bool GridData::IsCleared() const {
		for (int y = 0; y < _gridSize; y++) {
			for (int x = 0; x < _gridSize; x++) {
				if (!_cells[y][x]) {
					return false;
				}
			}
		}
		return true;
	}

	bool GridData::GetCell(int x, int y) const {
		if (x < 0 || x >= _gridSize || y < 0 || y >= _gridSize) {
			return false;
		}
		return _cells[y][x];
	}

	int GridData::GetSize() const {
		return _gridSize;
	}
}
