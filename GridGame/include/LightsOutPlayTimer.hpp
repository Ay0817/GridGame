#pragma once

#include "Component.hpp"
#include "Text.hpp"

class LightsOutPlayTimer final : public Component {
private:
	float _time = 0.f;
	bool _isRunning = true;

	Text* _text = nullptr;
public:
	LightsOutPlayTimer();

	virtual void Begin() override;

	virtual void Update() override;

	virtual void Draw() const override;

	void Stop();

	void Reset();
};
