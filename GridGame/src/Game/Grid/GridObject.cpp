#include <DxLib.h>

#include "../../include/GridObject.hpp"

GridObject::GridObject(const std::string& name, int size)
	: GameObject(name)
	, _grid(size)
{}

void GridObject::Begin() {
	if (_clearSE == -1) {
		_clearSE = LoadSoundMem("Resources/Sounds/SE/Clear.mp3");
		ChangeVolumeSoundMem(128, _clearSE);
	}
}

void GridObject::Update() {
	if (!_isCleared && _grid.IsCleared()) {
		_isCleared = true;
		PlaySoundMem(_clearSE, DX_PLAYTYPE_BACK);
	}
	
	if (!_grid.IsCleared() && _isCleared) {
		_isCleared = false;
	}
}
