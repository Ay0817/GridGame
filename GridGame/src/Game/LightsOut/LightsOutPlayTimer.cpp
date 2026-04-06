#include <cassert>
#include <format>

#include <Game/LightsOut/LightsOutPlayTimer.hpp>
#include <Core/GameObject.hpp>
#include <AyLib/Time.hpp>

namespace Game
{
    LightsOutPlayTimer::LightsOutPlayTimer()
        : Component()
    {}

    void LightsOutPlayTimer::Begin() {
        auto owner = GetOwner();

        _text = owner->GetComponent<UI::Text>();

        assert(_text != nullptr);
    }

    void LightsOutPlayTimer::Update() {
        if (_isRunning) {
            _time += AyLib::Time::GetDeltaTime();
        }
    }

    void LightsOutPlayTimer::Draw() const {
        auto total = static_cast<int>(_time * 1000.f);
        auto min = total / 60000;
        auto sec = (total / 1000) % 60;
        auto ms = (total / 10) % 100;

        _text->SetText(std::format("        {:02}:{:02}.{:02}", min, sec, ms));
    }
    void LightsOutPlayTimer::Stop() {
        _isRunning = false;
    }

    void LightsOutPlayTimer::Reset() {
        _time = 0.f;
        _isRunning = true;
    }
}
