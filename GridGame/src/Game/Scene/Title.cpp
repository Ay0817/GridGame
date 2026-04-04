#include <cassert>

#include "../../../include/Title.hpp"
#include "../../../include/Palette.hpp"
#include "../../../include/AssetResolver.hpp"
#include "../../../include/TitleController.hpp"
#include "../../../include/DxLap.hpp"
#include "../../../include/Grid.hpp"
#include "../../../include/GridRenderer.hpp"
#include "../../../include/TitleBgAnimation.hpp"
#include "../../../include/TitlePromptAnimation.hpp"
#include "../../../include/Sprite.hpp"
#include "../../../include/SpriteRenderer.hpp"
#include "../../../include/GeneralButton.hpp"
#include "../../../include/RectTransform.hpp"
#include "../../../include/GestureDetector.hpp"

Title::Title(const std::string& name)
	: Scene(name)
{}

void Title::Begin() {
	auto screen = Window::GetSizeF();

	auto titleBg = AddObject<GameObject>("titleBg");
	auto titleName = AddObject<GameObject>("title", Transform({ screen.x / 2, screen.y - 100.f }));
	auto title = AddObject<GameObject>("title", Transform({ screen / 2 }));

	auto square = AssetResolver::Load<Font>("SquareFont Outline", "Resources/Fonts/Squareo.ttf", FontInfo{ 128, 4, FontType::ANTI_ALIASING });
	auto maru = AssetResolver::Load<Font>("Zen Maru Gothic Medium Outline", "Resources/Fonts/ZenMaruGothic-Medium.ttf", FontInfo{ 32, 2, FontType::ANTI_ALIASING });

	titleName->AddComponent<TitlePromptAnimation>();
	titleName->AddComponent<Text>(TextInfo{ "CLICK TO START", maru, TextAlign{}, Palette::Basic::Black });
	//titleName->AddComponent<Text>(TextInfo{ "CLICK TO START", maru, TextAlign{}, Palette::Vspo::Ema });

	title->AddComponent<Text>(TextInfo{ "LIGHTS OUT", square, TextAlign{}, Palette::Basic::Black });
	//title->AddComponent<Text>(TextInfo{ "LIGHTS OUT", square, TextAlign{}, Palette::Vspo::Uruha });
	title->AddComponent<TitleController>();
	
	titleBg->AddComponent<TitleBgAnimation>();
	titleBg->AddComponent<Grid>(16, true);
	//titleBg->AddComponent<GridRenderer>(GridConfig{ 80, Window::GetSize().first / 2, Window::GetSize().second / 2 });

	//auto nazupi = AddObject<GameObject>("nazupi", Transform({ screen.x / 2, screen.y / 2 }));
	auto image = AssetResolver::Load<Image>("Nazupi", "Resources/Images/Nazupi.png");
	auto sprite = Sprite(image.get());

	//nazupi->AddComponent<SpriteRenderer>(sprite);

	auto button = AddObject<GameObject>("button", Transform({ screen.x / 2, screen.y / 2 }));
	button->AddComponent<Audio>();
	button->AddComponent<RectTransform>(Vector2{ screen.x / 2, screen.y / 2 }, Vector2{ 200.f, 80.f });
	button->AddComponent<GeneralButton>();
	button->AddComponent<GestureDetector>();

	Scene::Begin();
}
