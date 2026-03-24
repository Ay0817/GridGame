#include "../../include/Asset.hpp"

Asset::Asset(const std::string& name)
	: _name(name)
	, _handle(-1)
{}

int Asset::GetHandle() const {
	return _handle;
}

std::string Asset::GetName() {
	return _name;
}
