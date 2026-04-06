#pragma once

#include "Component.hpp"
#include "AyLib/Vector2.hpp"

namespace Core
{
	/// @brief 
	class Transform final : public Component {
	public:
		AyLib::Vector2 position;
		AyLib::Vector2 scale;
		float angle;
	public:
		/// @brief コンストラクタ
		/// @param position 座標
		/// @param scale スケール
		/// @param angle 角度
		Transform(const AyLib::Vector2& position = AyLib::Vector2::zero(), const AyLib::Vector2& scale = AyLib::Vector2::one(), float angle = 0.f);
	};
}
