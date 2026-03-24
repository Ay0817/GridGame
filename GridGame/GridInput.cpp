#include <DxLib.h>

#include "GridInput.hpp"
#include "GridObject.hpp"
#include "Input.hpp"

GridInput::GridInput(const GridConfig& config)
	: Component()
	, _gridConfig(config)
{}

void GridInput::Begin() {
	auto obj = static_cast<GridObject*>(GetOwner());
	_grid = &obj->GetGrid();

	if (_clickSE == -1) {
		_clickSE = LoadSoundMem("Resources/Sounds/SE/Click.mp3");
		ChangeVolumeSoundMem(128, _clickSE);
	}
}

void GridInput::Update() {
	// マウス取得
	auto [mx, my] = AyLib::Input::GetMousePosition();
	auto clicked = AyLib::Input::GetMouseButtonDown(AyLib::MouseButtons::Left);

	// グリッド情報
	auto size = _grid->GetSize();
	auto sx = _gridConfig.cx - (size * _gridConfig.cellSize) / 2;
	auto sy = _gridConfig.cy - (size * _gridConfig.cellSize) / 2;

	// 範囲確認
	auto isInside = mx >= sx && mx < sx + size * _gridConfig.cellSize && my >= sy && my < sy + size * _gridConfig.cellSize;

	if (clicked && isInside) {

		auto gx = (mx - sx) / _gridConfig.cellSize;
		auto gy = (my - sy) / _gridConfig.cellSize;

		_grid->ToggleAround(gx, gy);

		PlaySoundMem(_clickSE, DX_PLAYTYPE_BACK);
	}
}
