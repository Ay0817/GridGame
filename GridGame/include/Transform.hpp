#pragma once

#include "Component.hpp"
#include "Vector2.hpp"

/// @brief 
class Transform final : public Component {
public:
	Vector2 position;
	Vector2 scale;
	float angle;
public:
	/// @brief コンストラクタ
	/// @param position 座標
	/// @param scale スケール
	/// @param angle 角度
	Transform(const Vector2& position = Vector2::zero(), const Vector2& scale = Vector2::one(), float angle = 0.f);
};
