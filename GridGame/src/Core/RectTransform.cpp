#include "../../include/RectTransform.hpp"
#include "../../include/GameObject.hpp"
#include "../../include/SpriteRenderer.hpp"

RectTransform::RectTransform(const Vector2& pos, const Vector2& size, const Vector2& pivot)
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

Rect RectTransform::GetRect() const {
	auto left = position.x - size.x * pivot.x;
	auto top  = position.y - size.y * pivot.y;

	return Rect{ left, top, size.x, size.y };
}

