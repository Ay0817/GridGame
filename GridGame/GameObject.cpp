#include "GameObject.hpp"

GameObject::GameObject(const std::string& name)
	: _name(name)
	, _instanceID(0)
	, _active(true)
	, _destroyed(false)
	, _isInit(false)
{}

void GameObject::Begin() {
	if (_destroyed) {
		return;
	}

	for (auto& component : _components) {
		component->Begin();
	}

	_isInit = true;
}

void GameObject::Update() {
	if (_destroyed) {
		return;
	}

	if (!_isInit) {
		Begin();
	}

	for (auto& component : _components) {
		component->Update();
	}
}

void GameObject::LateUpdate() {
	if (_destroyed) {
		return;
	}

	for (auto& component : _components) {
		component->LateUpdate();
	}
}

void GameObject::Draw() const {
	if (_destroyed) {
		return;
	}

	for (auto& component : _components) {
		component->Draw();
	}
}

void GameObject::End() {
	for (auto& component : _components) {
		component->End();
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
