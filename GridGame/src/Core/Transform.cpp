#include <Core/Transform.hpp>

namespace Core
{
	Transform::Transform(const AyLib::Vector2& position, const AyLib::Vector2& scale, float angle)
		: Component()
		, position(position)
		, scale(scale)
		, angle(angle)
	{}
}
