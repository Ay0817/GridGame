#include <DxLib.h>
#include <cassert>

#include "../../../include/GridInput.hpp"
#include "../../../include/GridObject.hpp"
#include "../../../include/Input.hpp"
#include "../../../include/AssetResolver.hpp"

GridInput::GridInput(const GridConfig& config)
	: Component()
	, _gridConfig(config)
{}

void GridInput::Begin() {
	auto obj = dynamic_cast<GridObject*>(GetOwner());

	_grid = &obj->GetGrid();
	_clickSound.audio = obj->GetComponent<Audio>();

	assert(_grid != nullptr);
	assert(_clickSound.audio != nullptr);

	_clickSound.soundData = AssetResolver::Load<SoundData>("Click", "Resources/Sounds/SE/Click.mp3");
}

void GridInput::Update() {
	// マウス取得
	auto [mx, my] = Input::GetMousePosition();
	auto clicked = Input::GetMouseButtonDown(MouseButtons::Left);

	// グリッド情報
	auto size = _grid->GetSize();

	// 範囲内でクリックしたとき
	if (clicked && _gridConfig.IsInside(mx, my, size)) {
		auto [gx, gy] = _gridConfig.ScreenToGrid(mx, my, size);
			 
		_grid->ToggleAround(gx, gy);

		if (_clickSound.audio) {
			_clickSound.audio->Play(_clickSound.soundData);
		}
	}
}
