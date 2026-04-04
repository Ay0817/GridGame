#include "../../include/GameObject.hpp"

GameObject::GameObject(const std::string& name)
	: _name(name)
	, _instanceID(0)
	, _active(true)
	, _destroyed(false)
	, _isInit(false)
{}

GameObject::GameObject(const std::string & name, const Transform & transform)
	: _name(name)
	, _instanceID(0)
	, _active(true)
	, _destroyed(false)
	, _isInit(false)
	, _transfrom(transform)
{}

void GameObject::Begin() {
	if (_destroyed || !_active) {
		return;
	}

	for (auto& component : _components) {
		if (component->GetEnable()) {
			component->Begin();
		}
	}

	_isInit = true;
}

void GameObject::Update() {
	if (_destroyed || !_active) {
		return;
	}

	if (!_isInit) {
		Begin();
	}

	for (auto& component : _components) {
		if (component->GetEnable()) {
			component->Update();
		}
	}
}

void GameObject::LateUpdate() {
	if (_destroyed || !_active) {
		return;
	}

	for (auto& component : _components) {
		if (component->GetEnable()) {
			component->LateUpdate();
		}
	}
}

void GameObject::Draw() const {
	if (_destroyed || !_active) {
		return;
	}

	for (auto& component : _components) {
		if (component->GetEnable()) {
			component->Draw();
		}
	}
}

void GameObject::End() {
	for (auto& component : _components) {
		if (component->GetEnable()) {
			component->End();
		}
	}
}

void GameObject::SetDestroyed(bool state) {
	_destroyed = state;
}

void GameObject::SetActive(bool state) {
	_active = state;
}

bool GameObject::GetActive() const {
	return _active;
}

unsigned int GameObject::GetInstaceID() const {
	return _instanceID;
}

std::string GameObject::GetName() {
	return _name;
}

void GameObject::SetName(const std::string& name) {
	_name = name;
}
