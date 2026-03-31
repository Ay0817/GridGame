#include <cassert>

#include "../../../include/LightsOutInput.hpp"
#include "../../../include/GameObject.hpp"
#include "../../../include/AssetResolver.hpp"
#include "../../../include/Input.hpp"

LightsOutInput::LightsOutInput(const GridConfig& config)
	: Component()
	, _gridConfig(config)
{}

void LightsOutInput::Begin() {
	auto owner = GetOwner();

	_grid = owner->GetComponent<Grid>();
	_clickSound.audio = owner->GetComponent<Audio>();

	assert(_grid != nullptr);
	assert(_clickSound.audio != nullptr);

	_clickSound.soundData = AssetResolver::Load<SoundData>("Click", "Resources/Sounds/SE/Click.mp3");
}

void LightsOutInput::Update() {
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
