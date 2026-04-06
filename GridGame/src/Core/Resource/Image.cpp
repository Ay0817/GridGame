#include <DxLib.h>

#include <Core/Resource/Image.hpp>

namespace Core::Resource
{
	Image::Image(const std::string& name, const std::string& path)
		: Asset(name)
		, _width(0.f)
		, _height(0.f)
	{
		if (_handle == -1) {
			_handle = LoadGraph(path.data());

			if (_handle != -1) {
				GetGraphSizeF(_handle, &_width, &_height);
			}
		}
	}

	Image::~Image() {
		Release();
	}

	void Image::Release() {
		if (_handle != -1) {
			DeleteGraph(_handle);
		}
	}

	float Image::GetWidth() const {
		return _width;
	}

	float Image::GetHeight() const {
		return _height;
	}

	AyLib::Vector2 Image::GetSize() const {
		return { _width, _height };
	}
}
