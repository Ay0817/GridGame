#pragma once

#include "Component.hpp"
#include "Vector2.hpp"
#include "Rect.hpp"

class RectTransform final : public Component {
public:
	Vector2 position;
	Vector2 size;
	Vector2 pivot;
public:
	/// @brief コンストラクタ
	RectTransform(const Vector2& pos, const Vector2& size, const Vector2& pivot = Vector2::half());

	/// @brief 初期化処理
	virtual void Begin() override;

	/// @brief Rectを取得
	Rect GetRect() const;

	/// @brief 
	bool Contains(const Vector2& pos) const;
};
