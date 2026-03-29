#pragma once

#include <memory>
#include <string>

#include "SceneManager.hpp"
#include "Scene.hpp"
#include "TransitionManager.hpp"

namespace SceneAPI {
	/// @brief シーンを切り替える
	/// @tparam ...Args 切り替えるシーンの引数の型
	/// @tparam T 切り替えるシーンの型
	/// @param ...args 切り替えるシーンの引数
	template<IsScene T, typename... Args>
	void Change(Args&&... args) {
		SceneManager::LoadScene(std::make_unique<T>(std::forward<Args>(args)...));
	}

	/// @brief シーンを切り替える(フェード処理有)
	/// @tparam ...Args 切り替えるシーンの引数の型
	/// @tparam T 切り替えるシーンの型
	/// @param ...args 切り替えるシーンの引数
	template<IsScene T, typename... Args>
	void ChangeWithTransition(Args&&... args) {
		if (TransitionManager::IsPlaying()) {
			return;
		}

		TransitionManager::Play(
			[args...]() {
			SceneManager::LoadScene(std::make_unique<T>(std::forward<Args>(args)...));
			});
	}

	/// @brief 現在のシーン名を取得する
	/// @return 現在のシーン名
	std::string GetCurrentSceneName() {
		auto scene = SceneManager::GetCurrentScene();

		return scene ? scene->GetName() : "No Scene";
	}
}
