#pragma once

#include <memory>
#include <vector>
#include <unordered_map>

#include "GameObject.hpp"

namespace Core
{
	/// @brief ゲームオブジェクトの生成・検索・更新・描画・破棄を制御する管理クラスです。
	class GameObjectManager final {
	private:
		std::vector<std::unique_ptr<GameObject>> _gameObjects; // 所有している GameObject
		std::unordered_map<std::string, GameObject*> _nameMap; // 名前検索
		std::vector<GameObject*> _destroyScheduled;            // 削除予定の GameObject を保持
	private:
		/// @brief 破棄予定のゲームオブジェクトを処理する
		void ProcessDestroy();
	public:
		/// @brief 初期化処理
		void Init();

		/// @brief 終了時処理
		void Finalize();

		/// @brief 初期化処理
		void Begin();

		/// @brief 更新処理
		void Update();

		/// @brief 通常の更新処理の後に行う処理
		void LateUpdate();

		/// @brief 更新処理
		void Draw() const;

		/// @brief 終了時処理
		void End();

		/// @brief GameObject を破棄する
		/// @param name 破棄したい GameObject 名
		void Destroy(const std::string& name);

		/// @brief GameObject を破棄する
		/// @param object 破棄したい GameObject へのポインタ
		void Destroy(const std::unique_ptr<GameObject>& object);

		/// @brief GameObject を探す
		/// @tparam T 探したい GameObject の型
		/// @param name GameObject 名
		/// @return 探したい GameObject
		template <class T>
		[[nodiscard]]
		T* Find(const std::string& name) {
			auto it = _nameMap.find(name);

			if (it == _nameMap.end()) {
				return nullptr;
			}

			return dynamic_cast<T*>(it->second);
		}

		/// @brief GameObject 生成する
		/// @tparam T 生成したい GameObject の型
		/// @tparam ...Args 生成したい GameObject の引数
		/// @param ...args 引数
		/// @return 生成された GameObject
		template <class T, class... Args>
		[[nodiscard]]
		T* Create(Args&&... args) {
			auto obj = std::make_unique<T>(std::forward<Args>(args)...);
			auto ptr = obj.get();

			_gameObjects.emplace_back(std::move(obj));

			auto name = ptr->GetName();

			_nameMap.emplace(name, ptr);

			return ptr;
		}
	};
}
