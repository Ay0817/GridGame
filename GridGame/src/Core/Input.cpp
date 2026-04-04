#include "../../include/Input.hpp"
#include "../../include/InputSystem.hpp"

bool Input::GetKey(Keys key) {
	return InputSystem::keyInputs[std::to_underlying(key)] == InputSystem::State::PRESS;
}

bool Input::GetKeyDown(Keys key) {
	return InputSystem::keyInputs[std::to_underlying(key)] == InputSystem::State::PRESSING;
}

bool Input::GetKeyUp(Keys key) {
	return InputSystem::keyInputs[std::to_underlying(key)] == InputSystem::State::RELEASING;
}

bool Input::GetMouseButton(MouseButtons button) {
	return InputSystem::mouseInputs[std::to_underlying(button)] == InputSystem::State::PRESS;
}

bool Input::GetMouseButtonDown(MouseButtons button) {
	return InputSystem::mouseInputs[std::to_underlying(button)] == InputSystem::State::PRESSING;
}

bool Input::GetMouseButtonUp(MouseButtons button) {
	return InputSystem::mouseInputs[std::to_underlying(button)] == InputSystem::State::RELEASING;
}

Vector2 Input::GetMousePosition() {
	return InputSystem::position;
}

Vector2 Input::GetMouseDelta() {
	return InputSystem::delta;
}
