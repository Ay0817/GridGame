#include "../../include/Transform.hpp"

Transform::Transform(const Vector2& position, const Vector2& scale, float angle)
	: Component()
	, position(position)
	, scale(scale)
	, angle(angle)
{}
