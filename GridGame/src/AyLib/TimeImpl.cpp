#include <chrono>
#include <thread>

#include <AyLib/TimeImpl.hpp>

namespace AyLib
{
	static std::chrono::steady_clock::time_point start;
	static std::chrono::steady_clock::time_point last;

	double TimeImpl::time = 0.0;
	double TimeImpl::unscaledTime = 0.0;
	double TimeImpl::delta = 0.0;
	double TimeImpl::unscaledDelta = 0.0;
	float  TimeImpl::scale = 1.f;

	void TimeImpl::Init() {
		start = last = std::chrono::steady_clock::now();
		time = unscaledTime = 0.0;
	}

	void TimeImpl::Update() {
		auto now = std::chrono::steady_clock::now();
		std::chrono::duration<double> d = now - last;

		unscaledDelta = d.count();
		delta = unscaledDelta * scale;

		unscaledTime += unscaledDelta;
		time += delta;

		last = now;
	}
}
