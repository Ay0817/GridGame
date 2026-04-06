#include <cassert>

#include <Game/Title/TitleBgAnimation.hpp>
#include <Core/GameObject.hpp>
#include <AyLib/Time.hpp>
#include <AyLib/Random.hpp>

namespace Game
{
	void TitleBgAnimation::Begin() {
		auto owner = GetOwner();

		_grid = owner->GetComponent<GridData>();

		assert(_grid != nullptr);
	}

	void TitleBgAnimation::Update() {
		_timer += AyLib::Time::GetDeltaTime();

		if (_timer > _interval) {
			_timer = 0.f;

			auto size = _grid->GetSize();

			auto x = AyLib::Random::Range(0, size);
			auto y = AyLib::Random::Range(0, size);

			_grid->Toggle(x, y);
		}
	}
}
