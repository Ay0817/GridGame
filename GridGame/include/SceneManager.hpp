#pragma once

#include <stack>
#include <vector>
#include <memory>
#include <concepts>
#include <string>
#include <string_view>
#include <format>

class Scene; // 前方宣言

template <typename T>
concept IsScene = std::derived_from<T, Scene>; // コンセプト

/// @brief シーンの生成・切り替え・更新・描画・破棄を制御する管理クラスです。
class SceneManager final {
private:
	static std::vector<std::unique_ptr<Scene>> _scenes; // 保持しているシーン
	static std::unique_ptr<Scene> _nextScene;           // 次にロードするシーン
private:
	SceneManager() = delete;

	/// @brief シーン切り替え処理
	static void ProcessLoadScene();
public:
	/// @brief 初期化処理
	/// @tparam T 最初の Scene の型 
	/// @param name シーン名
	template <IsScene T>
	static void Init(const std::string& name) {
		auto scene = std::make_unique<T>(name);

		scene->Begin();

		_scenes.emplace_back(std::move(scene));
	}

	/// @brief 更新処理
	static void Update();

	/// @brief 描画処理
	static void Draw();

	/// @brief 終了時処理
	static void End();

	/// @brief シーンを切り替える
	/// @param scene 切り替えるシーンへのユニークポインタ。
	static void LoadScene(std::unique_ptr<Scene> scene);

	/// @brief 現在のシーンを取得
	/// @return 現在の Scene へのポインタ
	[[nodiscard]]
	static Scene* GetCurrentScene();
};
