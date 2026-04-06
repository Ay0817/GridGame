#include <cassert>

#include <Game/LightsOut/LightsOut.hpp>
#include <Core/GameObject.hpp>
#include <Core/Resource/AssetResolver.hpp>

namespace Game
{
	void LightsOut::Begin() {
		auto owner = GetOwner();

		_clearSound.audio = owner->GetComponent<Audio::SoundPlayer>();
		_grid = owner->GetComponent<GridData>();
		_playTimer = owner->GetComponent<LightsOutPlayTimer>();

		assert(_clearSound.audio != nullptr);
		assert(_grid != nullptr);
		assert(_playTimer != nullptr);

		_clearSound.soundData = Resource::AssetResolver::Load<Resource::SoundData>("Clear", "Resources/Sounds/SE/Clear.mp3");
	}

	void LightsOut::Update() {
		if (!_isCleared && _grid->IsCleared()) {
			_isCleared = true;
			if (_clearSound.audio) {
				_clearSound.audio->Play(_clearSound.soundData);
			}

			if (_playTimer) {
				_playTimer->Stop();
			}
		}

		if (!_grid->IsCleared() && _isCleared) {
			_isCleared = false;
		}
	}
}
