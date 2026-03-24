#pragma once

#include <memory>

// 前方宣言
class GameObject; 

/// @brief ゲームオブジェクトに機能を付与するためのコンポーネント基底クラス
class Component {
protected:
	GameObject* _owner = nullptr; // 自身を所持している GameObject へのポインタ
public:
	/// @brief デストラクタ
	virtual ~Component() = default;

	/// @brief 初期化処理
	virtual void Begin() {}

	/// @brief 更新処理
	virtual void Update() {}

	/// @brief 通常の更新処理の後に行う処理
	virtual void LateUpdate() {}

	/// @brief 描画処理
	virtual void Draw() const {}

	/// @brief 終了時処理
	virtual void End() {}

	/// @brief 所有者をセットする
	/// @param owner 所有者 のポインタ
	void SetOwner(GameObject* owner) {
		_owner = owner;
	}

	/// @brief 自身を所持している GameObject へのポインタ を返す
	/// @return 自身を所持している GameObject へのポインタ
	GameObject* GetOwner() const {
		return _owner;
	}
};
