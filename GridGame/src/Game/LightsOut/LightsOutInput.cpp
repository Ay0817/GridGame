#include <cassert>

#include <Game/LightsOut/LightsOutInput.hpp>
#include <Core/GameObject.hpp>
#include <Core/Input.hpp>
#include <Core/Resource/AssetResolver.hpp>

namespace Game
{
	LightsOutInput::LightsOutInput(const GridConfig& config)
		: Component()
		, _gridConfig(config)
	{}

	void LightsOutInput::Begin() {
		auto owner = GetOwner();

		_grid = owner->GetComponent<GridData>();
		_clickSound.audio = owner->GetComponent<Audio::SoundPlayer>();

		assert(_grid != nullptr);
		assert(_clickSound.audio != nullptr);

		_clickSound.soundData = Resource::AssetResolver::Load<Resource::SoundData>("Click", "Resources/Sounds/SE/Click.mp3");
	}

	void LightsOutInput::Update() {
		// マウス取得
		auto [mx, my] = Input::GetMousePosition();
		auto clicked = Input::GetMouseButtonDown(MouseButtons::Left);

		// グリッド情報
		auto size = _grid->GetSize();

		// 範囲内でクリックしたとき
		if (clicked && _gridConfig.IsInside(static_cast<int>(mx), static_cast<int>(my), size)) {
			auto [gx, gy] = _gridConfig.ScreenToGrid(static_cast<int>(mx), static_cast<int>(my), size);

			_grid->ToggleAround(gx, gy);

			if (_clickSound.audio) {
				_clickSound.audio->Play(_clickSound.soundData);
			}
		}
	}
}
