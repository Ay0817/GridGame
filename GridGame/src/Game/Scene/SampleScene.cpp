#include "../../include/SampleScene.hpp"
#include "../../include/GridObject.hpp"
#include "../../include/GridInput.hpp"
#include "../../include/GridRenderer.hpp"

SampleScene::SampleScene(const std::string& name)
	: Scene(name)
	, _gridConfig{ 100, 400, 300 }
{}

void SampleScene::Begin() {
	auto grid = AddObject<GridObject>("grid", 3);

	auto gridInput    = grid->AddComponent<GridInput>(_gridConfig);
	auto gridRenderer = grid->AddComponent<GridRenderer>(_gridConfig);

	Scene::Begin();
}
