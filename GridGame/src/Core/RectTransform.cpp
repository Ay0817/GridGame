#include <Core/RectTransform.hpp>
#include <Core/GameObject.hpp>
#include <Core/SpriteRenderer.hpp>

namespace Core
{
	RectTransform::RectTransform(const AyLib::Vector2& pos, const AyLib::Vector2& size, const AyLib::Vector2& pivot)
		: position(pos)
		, size(size)
		, pivot(pivot)
	{}

	void RectTransform::Begin() {
		auto owner = GetOwner();
		auto spriteRenderer = owner->GetComponent<SpriteRenderer>();

		if (spriteRenderer) {
			const auto& sprite = spriteRenderer->GetSprite();
			auto uv = sprite.GetUV();

			size = { uv.w, uv.h };
		}
	}

	AyLib::Rect RectTransform::GetRect() const {
		auto left = position.x - size.x * pivot.x;
		auto top = position.y - size.y * pivot.y;

		return AyLib::Rect{ left, top, size.x, size.y };
	}
}
