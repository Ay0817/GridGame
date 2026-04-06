#pragma once

#include <string>
#include <memory>
#include <vector>

#include "Component.hpp"
#include "Transform.hpp"

namespace Core
{
	/// @brief コンポーネントを所有し、ゲーム内の振る舞いを構成するゲームオブジェクトクラス
	class GameObject {
	protected:
		std::string _name;        // 名前
		unsigned int _instanceID; // id
		bool _active;             // アクティブ状態
		bool _destroyed;          // 破棄される予定か？
		bool _isInit;             // 初期化されたか？

		std::vector<std::unique_ptr<Component>> _components; // 所有している Component
		Transform _transfrom; // Transfrom 
	public:
		/// @brief コンストラクタ
		/// @param name オブジェクト名
		GameObject(const std::string& name);

		/// @brief コンストラクタ
		/// @param name オブジェクト名
		/// @param transform (座標,スケール,角度)
		GameObject(const std::string& name, const Transform& transform);

		/// @brief デフォルトデストラクタ
		virtual ~GameObject() = default;

		/// @brief 初期化処理
		virtual void Begin();

		/// @brief 更新処理
		virtual void Update();

		/// @brief 通常の更新処理の後に行う処理
		virtual void LateUpdate();

		/// @brief 描画処理
		virtual void Draw() const;

		/// @brief 終了時処理
		virtual void End();

		/// @brief 破棄予定にセット
		/// @param state trueなら 破棄する, false なら破棄しない
		void SetDestroyed(bool state);

		/// @brief アクティブ状態を変更する
		/// @param state true なら アクティブ, false なら 非アクティブ
		void SetActive(bool state);

		/// @brief アクティブ状態を取得する
		/// @return true なら アクティブ, false なら 非アクティブ
		[[nodiscard]]
		bool GetActive() const;

		/// @brief インスタンスの ID を取得する
		/// @return インスタンスの ID 
		[[nodiscard]]
		unsigned int GetInstaceID() const;

		/// @brief オブジェクト名を取得する
		/// @return オブジェクト名
		[[nodiscard]]
		std::string GetName();

		/// @brief オブジェクト名を変更する
		/// @param name オブジェクト名
		void SetName(const std::string& name);

		/// @brief Component を追加する
		/// @tparam ...Args 引数の型
		/// @tparam T 追加する Component の型
		/// @param ...args 引数
		/// @return 追加された Component
		template<class T, class... Args>
		T* AddComponent(Args&&... args) {
			auto comp = std::make_unique<T>(std::forward<Args>(args)...);
			auto ptr = comp.get();

			comp->SetOwner(this);

			_components.emplace_back(std::move(comp));

			return ptr;
		}

		/// @brief 指定した型の Component を取得する
		/// @tparam T 取得したい Component の型
		/// @return 指定した型の Component
		template<class T>
		[[nodiscard]]
		T* GetComponent() {
			for (auto& c : _components) {
				if (auto casted = dynamic_cast<T*>(c.get())) {
					return casted;
				}
			}
			return nullptr;
		}

		/// @brief 所有している Component を取得する
		/// @return 所有している Componen
		[[nodiscard]]
		std::vector<Component*> GetComponents() const;

		/// @brief Transform を取得
		/// @return Transform
		[[nodiscard]]
		Transform& GetTransform();
	};
}
