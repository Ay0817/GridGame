#include <cassert>

#include "../../../include/TitleBgAnimation.hpp"
#include "../../../include/GameObject.hpp"
#include "../../../include/Random.hpp"
#include "../../../include/Time.hpp"

void TitleBgAnimation::Begin() {
	auto owner = GetOwner();

	_grid = owner->GetComponent<Grid>();

	assert(_grid != nullptr);
}

void TitleBgAnimation::Update() {
	_timer += Time::GetDeltaTime();

	if (_timer > _interval) {
		_timer = 0.f;

		auto size = _grid->GetSize();

		auto x = Random::Range(0, size);
		auto y = Random::Range(0, size);

		_grid->Toggle(x, y);
	}
}
