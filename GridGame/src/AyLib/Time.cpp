#include <AyLib/Time.hpp>
#include <AyLib/TimeImpl.hpp>
#include <AyLib/Math.hpp>

namespace AyLib
{
	float Time::GetTime() {
		return static_cast<float>(TimeImpl::time);
	}

	float Time::GetUnscaledTime() {
		return static_cast<float>(TimeImpl::unscaledTime);
	}

	float Time::GetDeltaTime() {
		return static_cast<float>(TimeImpl::delta);
	}

	float Time::GetUnscaledDeltaTime() {
		return static_cast<float>(TimeImpl::unscaledDelta);
	}

	void Time::SetScale(float scale) {
		TimeImpl::scale = Math::Max(0.f, scale);
	}
}
