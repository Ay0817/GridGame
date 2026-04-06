#include <DxLib.h>

#include <Core/TransitionManager.hpp> 
#include <AyLib/Time.hpp> 
#include <AyLib/Math.hpp> 

namespace Core
{
	TransitionManager TransitionManager::instance;

	void TransitionManager::Begin(std::function<void()> func) {
		state = State::FadeOut;
		timer = 0.f;
		onChange = func;
	}

	void TransitionManager::UpdateImpl() {
		if (state == State::None) {
			return;
		}

		timer += AyLib::Time::GetDeltaTime();

		if (state == State::FadeOut) {
			if (timer >= duration) {
				timer = 0.f;
				state = State::Switch;

				if (onChange) {
					onChange();
				}
			}
		}
		else if (state == State::Switch) {
			state = State::FadeIn;
		}
		else if (state == State::FadeIn) {
			if (timer >= duration) {
				state = State::None;
			}
		}
	}

	void TransitionManager::DrawImpl() const {
		if (state == State::None) {
			return;
		}

		auto t = timer / duration;
		t = AyLib::Math::Clamp(t, 0.f, 1.f);

		auto eased = Ease(t);
		auto alpha = 0.f;

		if (state == State::FadeOut) {
			alpha = eased;
		}
		else if (state == State::FadeIn) {
			alpha = 1.f - eased;
		}

		auto a = static_cast<int>(alpha * 255.f);

		int w, h;
		GetDrawScreenSize(&w, &h);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, a);
		DrawBox(0, 0, w, h, GetColor(0, 0, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	}

	float TransitionManager::Ease(float t) const {
		return t * t * t * (t * (6 * t - 15) + 10);
	}
}
