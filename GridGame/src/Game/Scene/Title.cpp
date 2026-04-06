#include <cassert>

#include <Game/Scenes/Title.hpp>
#include <AyLib/AyLib.hpp>
#include <Core/Core.hpp>
#include <Game/Grid/GridData.hpp>
#include <Game/Grid/GridRenderer.hpp>
#include <Game/Title/TitleController.hpp>
#include <Game/Title/TitleBgAnimation.hpp>
#include <Game/Title/TitlePromptAnimation.hpp>

namespace Game
{
	Title::Title(const std::string& name)
		: Scene(name)
	{}

	void Title::Begin() {
		auto screen = Window::GetSizeF();

		auto titleBg = AddObject<GameObject>("titleBg");
		auto titleName = AddObject<GameObject>("title", Transform({ screen.x / 2, screen.y - 100.f }));
		auto title = AddObject<GameObject>("title", Transform({ screen / 2 }));

		auto square = Resource::AssetResolver::Load<Resource::Font>("SquareFont Outline", "Resources/Fonts/Squareo.ttf", Resource::FontInfo{ 128, 4, Resource::FontType::ANTI_ALIASING });
		auto maru = Resource::AssetResolver::Load<Resource::Font>("Zen Maru Gothic Medium Outline", "Resources/Fonts/ZenMaruGothic-Medium.ttf", Resource::FontInfo{ 32, 2, Resource::FontType::ANTI_ALIASING });

		titleName->AddComponent<TitlePromptAnimation>();
		titleName->AddComponent<UI::Text>(UI::TextInfo{ "CLICK TO START", maru, UI::TextAlign{}, Palette::Basic::Black });
		//titleName->AddComponent<Text>(TextInfo{ "CLICK TO START", maru, TextAlign{}, Palette::Vspo::Ema });

		title->AddComponent<UI::Text>(UI::TextInfo{ "LIGHTS OUT", square, UI::TextAlign{}, Palette::Basic::Black });
		//title->AddComponent<Text>(TextInfo{ "LIGHTS OUT", square, TextAlign{}, Palette::Vspo::Uruha });
		title->AddComponent<TitleController>();

		titleBg->AddComponent<TitleBgAnimation>();
		titleBg->AddComponent<GridData>(16, true);
		//titleBg->AddComponent<GridRenderer>(GridConfig{ 80, Window::GetSize().first / 2, Window::GetSize().second / 2 });

		//auto nazupi = AddObject<GameObject>("nazupi", Transform({ screen.x / 2, screen.y / 2 }));
		auto image = Resource::AssetResolver::Load<Resource::Image>("Nazupi", "Resources/Images/Nazupi.png");
		auto sprite = UI::Sprite(image.get());

		//nazupi->AddComponent<SpriteRenderer>(sprite);

		auto button = AddObject<GameObject>("button", Transform({ screen.x / 2, screen.y / 2 }));
		button->AddComponent<Audio::SoundPlayer>();
		button->AddComponent<RectTransform>(Vector2{ screen.x / 2, screen.y / 2 }, Vector2{ 200.f, 80.f });
		button->AddComponent<UI::GeneralButton>();
		button->AddComponent<UI::GestureDetector>();

		Scene::Begin();
	}
}
