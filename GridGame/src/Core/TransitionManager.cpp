#include "../../include/TransitionManager.hpp"

void TransitionManager::Begin(std::function<void()> func) {
	state = State::FadeOut;
	timer = 0.f;
	onChange = func;
}

void TransitionManager::UpdateImpl() {

}

void TransitionManager::DrawImpl() {

}
