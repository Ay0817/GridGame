#include <assert.h>

#include "../../include/GestureDetector.hpp"
#include "../../include/Input.hpp"
#include "../../include/Time.hpp"
#include "../../include/GameObject.hpp"

GestureDetector::GestureDetector()
	: Component()
	, _pressTime(0.f)
	, _lastPressTime(0.f)
	, _rectTransform(nullptr)
{}

void GestureDetector::Begin() {
	auto owner = GetOwner();

	_rectTransform = owner->GetComponent<RectTransform>();

	assert(_rectTransform != nullptr);
}

void GestureDetector::Update() {
	auto isOver = IsPointerOver();
	auto now = Time::GetUnscaledTime();

	if (!_isPressed && Input::GetMouseButtonDown(MouseButtons::Left)){
		if (isOver) {
			_isPressed = true;
			_pressTime = now;

			OnPressedCallBack.Invoke(true);
		}
	}

	if (_isPressed && Input::GetMouseButtonUp(MouseButtons::Left)) {
		_isPressed = false;

		OnPressedCallBack.Invoke(false);

		if (isOver) {
			if (now - _lastPressTime >= CLICK_INTERVAL) {
				_lastPressTime = now;
				OnClickCallBack.Invoke();
			}
		}
		_isLongTapTriggered = false;
	}

	if (_isPressed && !isOver) {
		_isPressed = false;

		OnPressedCallBack.Invoke(false);

		_isLongTapTriggered = false;
	}

	if (_isPressed && !_isLongTapTriggered) {
		if (now - _pressTime >= LONG_TAP_TIME) {
			OnLongTappedCallBack.Invoke();

			_isLongTapTriggered = true;
		}
	}
}

bool GestureDetector::IsPointerOver() {
	auto rect = _rectTransform->GetRect();
	auto [x, y] = Input::GetMousePosition();

	return rect.Contains(x, y);
}
