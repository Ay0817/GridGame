#pragma once

#include "Renderer.hpp"
#include "Sprite.hpp"
#include "Transform.hpp"

/// @brief スプライトを描画
class SpriteRenderer final : public Renderer {
private:
	Sprite _sprite; // スプライトへのポインタ
	Transform* _transform; // Transform
public:
	/// @brief コンストラクタ
	/// @param sprite スプライトへのポインタ
	/// @param order 描画順
	/// @param layer 描画レイヤー
	SpriteRenderer(const Sprite& sprite, int order = 0, int layer = 0);

	/// @brief 初期化処理
	virtual void Begin() override;

	/// @brief 描画処理
	virtual void Draw() const override;

	/// @brief スプライトへのポインタを取得
	/// @return スプライトへのポインタ
	Sprite& GetSprite();
};
