#pragma once

#include "Core/Component.hpp"
#include "Core/UI/Text.hpp"

namespace Game
{
	using namespace Core;

	class LightsOutPlayTimer final : public Component {
	private:
		float _time = 0.f;
		bool _isRunning = true;

		UI::Text* _text = nullptr;
	public:
		LightsOutPlayTimer();

		virtual void Begin() override;

		virtual void Update() override;

		virtual void Draw() const override;

		void Stop();

		void Reset();
	};
}
