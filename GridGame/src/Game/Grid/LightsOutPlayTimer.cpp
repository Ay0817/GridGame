#include <cassert>
#include <format>

#include "../../../include/LightsOutPlayTimer.hpp"
#include "../../../include/Time.hpp"
#include "../../../include/GridObject.hpp"

LightsOutPlayTimer::LightsOutPlayTimer()
    : Component()
{}

void LightsOutPlayTimer::Begin() {
    auto obj = dynamic_cast<GridObject*>(GetOwner());

	_text = obj->GetComponent<Text>();

    assert(_text != nullptr);
}

void LightsOutPlayTimer::Update() {
    if (_isRunning) {
        _time += Time::GetDeltaTime();
    }
}

void LightsOutPlayTimer::Draw() const {
    auto total = static_cast<int>(_time * 1000.f);
    auto min = total / 60000;
    auto sec = (total / 1000) % 60;
    auto ms  = (total / 10) % 100;

    _text->SetText(std::format("        {:02}:{:02}.{:02}", min, sec, ms));
}
void LightsOutPlayTimer::Stop() {
    _isRunning = false;
}

void LightsOutPlayTimer::Reset() {
	_time = 0.f;
    _isRunning = true;
}
