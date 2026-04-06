#include <Core/Component.hpp>

namespace Core
{
	GameObject* Core::Component::GetOwner() const {
		return _owner;
	}

	void Component::SetEnable(bool state) {
		_enable = state;
	}

	bool Component::GetEnable() const{
		return _enable;
	}
}
