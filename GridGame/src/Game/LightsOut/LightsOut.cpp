#include <cassert>

#include "../../../include/LightsOut.hpp"
#include "../../../include/GameObject.hpp"
#include "../../../include/AssetResolver.hpp"

void LightsOut::Begin() {
	auto owner = GetOwner();

	_clearSound.audio = owner->GetComponent<Audio>();
	_grid = owner->GetComponent<Grid>();
	_playTimer = owner->GetComponent<LightsOutPlayTimer>();

	assert(_clearSound.audio != nullptr);
	assert(_grid != nullptr);
	assert(_playTimer != nullptr);

	_clearSound.soundData = AssetResolver::Load<SoundData>("Clear", "Resources/Sounds/SE/Clear.mp3");
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
