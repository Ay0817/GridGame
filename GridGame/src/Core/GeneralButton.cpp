#include <DxLib.h>
#include <cassert>

#include "../../include/GeneralButton.hpp"
#include "../../include/GameObject.hpp"
#include "../../include/AssetResolver.hpp"
#include "../../include/Palette.hpp"
#include "../../include/Transform.hpp"

GeneralButton::GeneralButton(std::shared_ptr<SoundData> soundData, float targetScale, float scaleDuration)
	: ButtonBase()
	, _target(targetScale)
	, _targetScale(targetScale)
	, _speed(scaleDuration)
	, _hasImage(false)
	, _buttonSE{nullptr, soundData}
	, _spriteRenderer(nullptr)
	, _transform(nullptr)
{}

void GeneralButton::Begin() {
	SetEnable(true);

	auto owner = GetOwner();
	_spriteRenderer = owner->GetComponent<SpriteRenderer>();

	if (_spriteRenderer) {
		_hasImage = true;
	}

	_scale = Vector2{ 1.f, 1.f };

	_buttonSE.audio = owner->GetComponent<Audio>();

	assert(_buttonSE.audio != nullptr);

	_transform = &owner->GetTransform();

	if (!_buttonSE.soundData) {
		_buttonSE.soundData = AssetResolver::Load<SoundData>("ButtonSE", "Resources/Sounds/SE/Tutorial.mp3");
	}

	ButtonBase::Begin();
}

void GeneralButton::Update() {
	//_scale.x += (_targetScale - _scale.x) * _speed;

	//if (_spriteRenderer) {
	//	_transform->scale = Vector2(_scale.x, _scale.x);
	//}


}

void GeneralButton::Draw() const {
	if (!_hasImage) {
		auto rect = _rectTransform->GetRect();

		auto w = rect.w * _scale.x;
		auto h = rect.h * _scale.y;

		auto cx = rect.x + rect.w * 0.5f;
		auto cy = rect.y + rect.h * 0.5f;

		int left   = static_cast<int>(cx - w * 0.5f);
		int right  = static_cast<int>(cx + w * 0.5f);
		int top    = static_cast<int>(cy - h * 0.5f);
		int bottom = static_cast<int>(cy + h * 0.5f);

		DrawBox(left, top, right, bottom, Palette::Basic::White.ToRGB(), true);
		DrawBox(left, top, right, bottom, Palette::Basic::Black.ToRGB(), false);
	}
}

void GeneralButton::OnClicked() {
	_targetScale = 1.f;

	if (_buttonSE.audio) {
		_buttonSE.audio->Play(_buttonSE.soundData);
	}
}

void GeneralButton::OnPressed(bool isPressed) {
	if (isPressed) {
		_targetScale = _target;
		_scale = Vector2{ _targetScale, _targetScale };
	}
	else {
		_targetScale = 1.0f;
		_scale = Vector2::one();
	}
}
