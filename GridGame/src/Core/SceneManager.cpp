#include <Core/SceneManager.hpp>
#include <Core/Scene.hpp>

namespace Core
{
	std::vector<std::unique_ptr<Scene>> SceneManager::_scenes = {};

	std::unique_ptr<Scene> SceneManager::_nextScene = nullptr;

	void SceneManager::Update() {
		if (auto scene = GetCurrentScene()) {
			scene->Update();
		}

		ProcessLoadScene();
	}

	void SceneManager::Draw() {
		if (auto scene = GetCurrentScene()) {
			scene->Draw();
		}
	}

	void SceneManager::End() {
		OnSceneChanging.Clear();
		OnSceneLoaded.Clear();
		OnSceneUnloaded.Clear();
	}

	void SceneManager::LoadScene(std::unique_ptr<Scene> scene) {
		if (!scene) {
			return;
		}

		_nextScene = std::move(scene);
	}

	Scene* SceneManager::GetCurrentScene() {
		if (_scenes.empty()) {
			return nullptr;
		}

		return _scenes.back().get();
	}

	void SceneManager::ProcessLoadScene() {
		if (!_nextScene) {
			return;
		}

		OnSceneChanging.Invoke();

		if (!_scenes.empty()) {
			_scenes.back()->End();

			OnSceneUnloaded.Invoke();

			_scenes.pop_back();
		}

		_scenes.emplace_back(std::move(_nextScene));
		_nextScene.reset();

		_scenes.back()->Begin();

		OnSceneLoaded.Invoke();
	}
}
