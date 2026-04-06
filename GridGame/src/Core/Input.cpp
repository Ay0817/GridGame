#include <Core/Input.hpp>
#include <Core/InputSystem.hpp>

namespace Core
{
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

	AyLib::Vector2 Input::GetMousePosition() {
		return InputSystem::position;
	}

	AyLib::Vector2 Input::GetMouseDelta() {
		return InputSystem::delta;
	}
}
