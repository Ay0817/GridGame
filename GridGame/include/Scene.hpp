#pragma once

#include <string>

#include "GameObjectManager.hpp"

/// @brief シーンの基底クラス
class Scene {
private:
	std::unique_ptr<GameObjectManager> _gameObjectManager; // GameObject を管理
protected:
	std::string _name; // シーン名
public:
	/// @brief コンストラクタ
	/// @param name シーン名
	Scene(const std::string& name);

	/// @brief デフォルトデストラクタ
	virtual ~Scene() = default;

	/// @brief 初期化処理
	virtual void Begin();

	/// @brief 終了時処理
	virtual void End();

	/// @brief 更新処理
	void Update();

	/// @brief 描画処理
	void Draw() const;

	/// @brief オブジェクトを生成する
	/// @tparam T 生成したい GameObject の型
	/// @tparam ...Args 生成したい GameObject の 引数
	/// @param ...args 引数
	/// @return 生成された GameObject
	template <class T, class... Args>
	T* AddObject(Args&&... args) {
		return _gameObjectManager->Create<T>(std::forward<Args>(args)...);
	}

	/// @brief シーン名を取得する
	/// @return シーン名
	std::string GetName() const { 
		return _name; 
	}
};
