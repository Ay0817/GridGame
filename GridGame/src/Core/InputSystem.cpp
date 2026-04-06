#include <DxLib.h>
#include <ranges>

#include <Core/InputSystem.hpp>

namespace Core
{
	std::array<InputSystem::State, 256> InputSystem::keyInputs = {};
	std::array<InputSystem::State, 3> InputSystem::mouseInputs = {};

	AyLib::Vector2 InputSystem::position = {};
	AyLib::Vector2 InputSystem::delta = {};

	InputSystem::State InputSystem::NextState(State current, bool pressd) noexcept {
		if (pressd) {
			return current == State::RELEASE ? State::PRESSING : current == State::PRESSING ? State::PRESS : current;
		}
		else {
			return (current == State::PRESS || current == State::PRESSING) ? State::RELEASING : State::RELEASE;
		}
	}

	void InputSystem::Update() {
		char buf[256];
		DxLib::GetHitKeyStateAll(buf);

		for (auto i : std::views::iota(0, 256)) {
			keyInputs[i] = NextState(keyInputs[i], buf[i]);
		}

		auto input = DxLib::GetMouseInput();
		int mx, my;
		DxLib::GetMousePoint(&mx, &my);

		auto newPos = AyLib::Vector2(mx, my);

		delta = newPos - position;

		position = newPos;

		for (auto i : std::views::iota(0, static_cast<int>(mouseInputs.size()))) {
			mouseInputs[i] = NextState(mouseInputs[i], input & (1 << i));
		}
	}

	void InputSystem::End() {

	}
}
