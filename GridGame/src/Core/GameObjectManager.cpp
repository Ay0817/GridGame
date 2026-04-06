#include <Core/GameObjectManager.hpp>

namespace Core
{
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
		}
	}

	void GameObjectManager::Update() {
		for (auto& object : _gameObjects) {
			if (!object->GetActive()) {
				continue;
			}

			object->Update();
		}
	}

	void GameObjectManager::LateUpdate() {
		for (auto& object : _gameObjects) {
			if (!object->GetActive()) {
				continue;
			}

			object->LateUpdate();
		}
	}

	void GameObjectManager::Draw() const {
		for (auto& object : _gameObjects) {
			if (!object->GetActive()) {
				continue;
			}

			object->Draw();
		}
	}

	void GameObjectManager::End() {
		for (auto& object : _gameObjects) {
			if (!object->GetActive()) {
				continue;
			}

			object->End();
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
}
