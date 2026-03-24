#include "../../include/Scene.hpp"

Scene::Scene(const std::string& name)
	: _name(name)
	, _gameObjectManager(std::make_unique<GameObjectManager>())
{}

void Scene::Begin() {
	_gameObjectManager->Begin();
}

void Scene::End() {
	_gameObjectManager->End();
}

void Scene::Update() {
	_gameObjectManager->Update();
	_gameObjectManager->LateUpdate();
}

void Scene::Draw() const {
	_gameObjectManager->Draw();
}
