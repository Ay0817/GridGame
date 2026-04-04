#include <cassert>

#include "../../include/ButtonBase.hpp"
#include "../../include/GameObject.hpp"
#include "../../include/Input.hpp"
#include "../../include/GestureDetector.hpp"

void ButtonBase::OnClickedHandler() {
	OnClicked();
	OnClickCallBack.Invoke();
}

void ButtonBase::OnPressedHandler(bool isPressed) {
	OnPressed(isPressed);
	OnPressedCallBack.Invoke(isPressed);
}

void ButtonBase::OnLongTappedHandler() {
	OnLongTapped();
	OnLongTappedCallback.Invoke();
}

void ButtonBase::OnClicked() 
{}

void ButtonBase::OnPressed(bool isPressed) 
{}

void ButtonBase::OnLongTapped()
{}

void ButtonBase::Begin() {
	auto owner = GetOwner();
    auto gesture = owner->GetComponent<GestureDetector>();

	assert(gesture != nullptr);

	_rectTransform = owner->GetComponent<RectTransform>();

	assert(_rectTransform != nullptr);

	gesture->OnClickCallBack.Add([this]() {OnClickedHandler(); });
	gesture->OnPressedCallBack.Add([this](bool isPressed) {OnPressedHandler(isPressed); });
	gesture->OnLongTappedCallBack.Add([this]() {OnLongTappedHandler(); });
}

void ButtonBase::End() {
	OnClickCallBack.Clear();
	OnPressedCallBack.Clear();
	OnLongTappedCallback.Clear();
}

void ButtonBase::SetEnable(bool state) {
	_isEnabled = state;
}

bool ButtonBase::IsEnabled() const {
	return _isEnabled;
}

bool ButtonBase::IsDisabled() const {
	return !_isEnabled;
}
