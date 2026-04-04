#include "../../../include/PlayScene.hpp"
#include "../../../include/Grid.hpp"
#include "../../../include/LightsOut.hpp"
#include "../../../include/LightsOutInput.hpp"
#include "../../../include/LightsOutPlayTimer.hpp"
#include "../../../include/GridRenderer.hpp"
#include "../../../include/Audio.hpp"
#include "../../../include/Text.hpp"
#include "../../../include/Palette.hpp"
#include "../../../include/AssetResolver.hpp"
#include "../../../include/DxLap.hpp"

PlayScene::PlayScene(const std::string& name)
	: Scene(name)
	, _gridConfig{ 100, Window::GetSize().first / 2, Window::GetSize().second / 2}
{}

void PlayScene::Begin() {
	auto lightsOut = AddObject<GameObject>("LightsOut", Transform({ 10.f, 15.f }));
	auto font = AssetResolver::Load<Font>("CascadiaCode", "Resources/Fonts/CascadiaCode.ttf", FontInfo{ 32, 4, FontType::ANTI_ALIASING });

	lightsOut->AddComponent<Grid>();
	lightsOut->AddComponent<LightsOut>();
	lightsOut->AddComponent<LightsOutPlayTimer>();
	lightsOut->AddComponent<LightsOutInput>(_gridConfig);
	lightsOut->AddComponent<GridRenderer>(_gridConfig);
	lightsOut->AddComponent<Audio>();
	lightsOut->AddComponent<Text>(TextInfo{ "", font, TextAlign{}, Palette::Vspo::Ema });

	Scene::Begin();
}
