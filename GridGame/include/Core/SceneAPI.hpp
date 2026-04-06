#pragma once

#include <memory>
#include <string>

#include "SceneManager.hpp"
#include "Scene.hpp"
#include "TransitionManager.hpp"
#include "AyLib/Action.hpp"

namespace Core::SceneAPI {
	/// @brief シーンを切り替える
	/// @tparam ...Args 切り替えるシーンの引数の型
	/// @tparam T 切り替えるシーンの型
	/// @param ...args 切り替えるシーンの引数
	template<IsScene T, typename... Args>
	[[nodiscard]]
		static inline void Change(Args&&... args) {
		SceneManager::LoadScene(std::make_unique<T>(std::forward<Args>(args)...));
	}

	/// @brief シーンを切り替える(フェード処理有)
	/// @tparam ...Args 切り替えるシーンの引数の型
	/// @tparam T 切り替えるシーンの型
	/// @param ...args 切り替えるシーンの引数
	template<IsScene T, typename... Args>
	[[nodiscard]]
		static inline void ChangeWithTransition(Args&&... args) {
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
	static inline std::string GetCurrentSceneName() {
		return SceneManager::GetCurrentScene()->GetName();
	}

	/// @brief シーン切り替え前のイベント
	static inline AyLib::Action<>& OnSceneChanging() {
		return SceneManager::OnSceneChanging;
	}

	/// @brief シーン切り替え後のイベント
	static inline AyLib::Action<>& OnSceneChanged() {
		return SceneManager::OnSceneLoaded;
	}

	/// @brief シーンアンロード時のイベント
	static inline AyLib::Action<>& OnSceneUnloaded() {
		return SceneManager::OnSceneUnloaded;
	}
}
