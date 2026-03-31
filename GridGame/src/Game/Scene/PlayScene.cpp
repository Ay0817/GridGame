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

PlayScene::PlayScene(const std::string& name)
	: Scene(name)
	, _gridConfig{ 100, 400, 300 }
{}

void PlayScene::Begin() {
	auto lightsOut = AddObject<GameObject>("LightsOut", Transform({ 10.f, 0 }));
	auto font = AssetResolver::Get<Font>("CascadiaCode");

	lightsOut->AddComponent<Grid>();
	lightsOut->AddComponent<LightsOut>();
	lightsOut->AddComponent<LightsOutPlayTimer>();
	lightsOut->AddComponent<LightsOutInput>(_gridConfig);
	lightsOut->AddComponent<GridRenderer>(_gridConfig);
	lightsOut->AddComponent<Audio>();
	lightsOut->AddComponent<Text>(TextInfo{ "", font, TextAlign::Center, Palette::Vspo::Ema });

	Scene::Begin();
}
