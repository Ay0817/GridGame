#include "../../include/GameObjectManager.hpp"

void GameObjectManager::ProcessDestroy() {
	for (auto go : _destroyScheduled) {
		_nameMap.erase(go->GetName());

		auto name = go->GetName();

		std::erase_if(_gameObjects,
			[&](const auto& ptr) {
				return ptr.get() == go;
			});
	}

	_destroyScheduled.clear();
}

void GameObjectManager::Init() {
	_gameObjects.clear();
}

void GameObjectManager::Finalize() {
	_gameObjects.clear();
}

void GameObjectManager::Begin() {
	for (auto& object : _gameObjects) {
		if (!object->GetActive()) {
			continue;
		}

		object->Begin();

		for (auto& comp : object->GetComponents()) {
			comp->Begin();
		}
	}
}

void GameObjectManager::Update() {
	for (auto& object : _gameObjects) {
		if (!object->GetActive()) {
			continue;
		}

		object->Update();

		for (auto& comp : object->GetComponents()) {
			comp->Update();
		}
	}
}

void GameObjectManager::LateUpdate() {
	for (auto& object : _gameObjects) {
		if (!object->GetActive()) {
			continue;
		}

		object->LateUpdate();

		for (auto& comp : object->GetComponents()) {
			comp->LateUpdate();
		}
	}
}

void GameObjectManager::Draw() const {
	for (auto& object : _gameObjects) {
		if (!object->GetActive()) {
			continue;
		}

		object->Draw();

		for (auto& comp : object->GetComponents()) {
			comp->Draw();
		}
	}
}

void GameObjectManager::End() {
	for (auto& object : _gameObjects) {
		if (!object->GetActive()) {
			continue;
		}

		object->End();

		for (auto& comp : object->GetComponents()) {
			comp->End();
		}
	}
}

void GameObjectManager::Destroy(const std::string& name) {
	for (auto& object : _gameObjects) {
		if (name == object->GetName()) {
			_destroyScheduled.emplace_back(object.get());
		}
	}
}

void GameObjectManager::Destroy(const std::unique_ptr<GameObject>& object) {
	_destroyScheduled.emplace_back(object.get());
}
