#include <cassert>

#include <Game/Title/TitlePromptAnimation.hpp>
#include <Core/GameObject.hpp>
#include <AyLib/Time.hpp>
#include <AyLib/Math.hpp>

namespace Game
{
	TitlePromptAnimation::TitlePromptAnimation()
		: Component()
		, _color(0, 0, 0, 0)
	{}

	void TitlePromptAnimation::Begin() {
		auto owner = GetOwner();

		_text = owner->GetComponent<UI::Text>();

		assert(_text != nullptr);

		_color = _text->GetColor();
	}

	void TitlePromptAnimation::Update() {
		_timer += AyLib::Time::GetDeltaTime();

		// min + (max - min) * ((sin + 1) / 2)

		auto a = 0.2f + 0.8f * ((AyLib::Math::Sin(_timer * 3.f) + 1.f) / 2.f);

		_color.a = static_cast<unsigned int>(a * 255);

		_text->SetColor(_color);
	}
}
