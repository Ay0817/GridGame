#include <DxLib.h>
#include <cassert>

#include "../../include/GridObject.hpp"
#include "../../../include/AssetResolver.hpp"

GridObject::GridObject(const std::string& name, int size)
	: GameObject(name)
	, _grid(size)
{}

void GridObject::Begin() {
	_clearSound.audio = GetComponent<Audio>();

	assert(_clearSound.audio != nullptr);

	_clearSound.soundData = AssetResolver::Load<SoundData>("Clear", "Resources/Sounds/SE/Clear.mp3");
}

void GridObject::Update() {
	if (!_isCleared && _grid.IsCleared()) {
		_isCleared = true;
		if (_clearSound.audio) {
			_clearSound.audio->Play(_clearSound.soundData);
		}
	}
	
	if (!_grid.IsCleared() && _isCleared) {
		_isCleared = false;
	}
}
