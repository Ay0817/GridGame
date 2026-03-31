#include <cassert>

#include "../../../include/Title.hpp"
#include "../../../include/Palette.hpp"
#include "../../../include/AssetResolver.hpp"
#include "../../../include/TitleController.hpp"
#include "../../../include/DxLap.hpp"

Title::Title(const std::string& name)
	: Scene(name)
{}

void Title::Begin() {
	auto screen = Window::GetSize();
	auto title = AddObject<GameObject>("title", Transform({ screen / 2 }));
	auto font = AssetResolver::Load<Font>("CascadiaCode", "Resources/Fonts/CascadiaCode.ttf", FontInfo{ 32, 2, FontType::ANTI_ALIASING });

	assert(font != nullptr);

	title->AddComponent<Text>(TextInfo{ "Lights Out", font, TextAlign::Center, Palette::Basic::Black });
	title->AddComponent<TitleController>();

	Scene::Begin();
}
