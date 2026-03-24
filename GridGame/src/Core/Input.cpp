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

std::pair<int, int> Input::GetMousePosition() {
	return InputSystem::position;
}

std::pair<int, int> Input::GetMouseDelta() {
	return InputSystem::delta;
}
