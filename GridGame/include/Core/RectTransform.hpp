#pragma once

#include "Component.hpp"
#include "AyLib/Vector2.hpp"
#include "AyLib/Rect.hpp"

namespace Core
{
	class RectTransform final : public Component {
	public:
		AyLib::Vector2 position;
		AyLib::Vector2 size;
		AyLib::Vector2 pivot;
	public:
		/// @brief コンストラクタ
		RectTransform(const AyLib::Vector2& pos, const AyLib::Vector2& size, const AyLib::Vector2& pivot = AyLib::Vector2::half());

		/// @brief 初期化処理
		virtual void Begin() override;

		/// @brief Rectを取得
		[[nodiscard]]
		AyLib::Rect GetRect() const;

		/// @brief 
		[[nodiscard]]
		bool Contains(const AyLib::Vector2& pos) const;
	};
}
