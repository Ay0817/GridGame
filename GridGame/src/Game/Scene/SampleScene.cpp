#include "../../../include/SampleScene.hpp"
#include "../../../include/GridObject.hpp"
#include "../../../include/GridInput.hpp"
#include "../../../include/GridRenderer.hpp"
#include "../../../include/Audio.hpp"
#include "../../../include/LightsOutPlayTimer.hpp"
#include "../../../include/Palette.hpp"
#include "../../../include/AssetResolver.hpp"

SampleScene::SampleScene(const std::string& name)
	: Scene(name)
	, _gridConfig{ 100, 400, 300 }
{}

void SampleScene::Begin() {
	auto grid = AddObject<GridObject>("grid", 3);
	auto font = AssetResolver::Get<Font>("CascadiaCode");

	grid->AddComponent<Audio>();
	grid->AddComponent<GridInput>(_gridConfig);
	grid->AddComponent<GridRenderer>(_gridConfig);
	grid->AddComponent<Text>(TextInfo{ "", font, TextAlign::Center, Palette::Vspo::Ema });
	grid->AddComponent<LightsOutPlayTimer>();

	Scene::Begin();
}
