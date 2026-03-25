#include "../../../include/SampleScene.hpp"
#include "../../../include/GridObject.hpp"
#include "../../../include/GridInput.hpp"
#include "../../../include/GridRenderer.hpp"
#include "../../../include/Audio.hpp"

SampleScene::SampleScene(const std::string& name)
	: Scene(name)
	, _gridConfig{ 100, 400, 300 }
{}

void SampleScene::Begin() {
	auto grid = AddObject<GridObject>("grid", 3);

	grid->AddComponent<Audio>();
	grid->AddComponent<GridInput>(_gridConfig);
	grid->AddComponent<GridRenderer>(_gridConfig);

	Scene::Begin();
}
