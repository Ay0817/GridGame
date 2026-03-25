#include <cassert>

#include "../../../include/Title.hpp"
#include "../../../include/Palette.hpp"
#include "../../../include/AssetResolver.hpp"

Title::Title(const std::string& name)
	: Scene(name)
	, _textInfo{ "Lights Out", nullptr, TextAlign::Center, Palette::Vspo::Ema }
	, _fontInfo{ 32, 2, FontType::ANTI_ALIASING }
{}

void Title::Begin() {
	auto title = AddObject<GameObject>("title", Transform({ 400.f, 300.f }));
	auto font = AssetResolver::Load<Font>("CascadiaCode", "Resources/Fonts/CascadiaCode.ttf", _fontInfo);

	assert(font != nullptr);

	_textInfo.font = font;

	title->AddComponent<Text>(_textInfo);

	Scene::Begin();
}
