#include <Core/UI/Sprite.hpp>

namespace Core::UI
{
	Sprite::Sprite(Resource::Image* image)
		: _name("")
		, _image(image)
		, _uv{ 0.f, 0.f, 0.f, 0.f }
		, _pivot(AyLib::Vector2(0.5f, 0.5f))
	{
		if (_image) {
			_uv = AyLib::Rect{
				0,
				0,
				_image->GetWidth(),
				_image->GetHeight()
			};
		}
	}

	Sprite::Sprite(Resource::Image* image, const AyLib::Rect& rect)
		: _name("")
		, _image(image)
		, _uv(rect)
		, _pivot(AyLib::Vector2(0.5f, 0.5f))
	{
	}

	Sprite::Sprite(Resource::Image* image, const AyLib::Vector2& vec)
		: _name("")
		, _image(image)
		, _uv{ 0, 0, 0, 0 }
		, _pivot(vec)
	{
		if (_image) {
			_uv = AyLib::Rect{
				0,
				0,
				_image->GetWidth(),
				_image->GetHeight()
			};
		}
	}

	Sprite::Sprite(Resource::Image* image, const AyLib::Rect& rect, const AyLib::Vector2& vec)
		: _name("")
		, _image(image)
		, _uv(rect)
		, _pivot(vec)
	{}

	void Sprite::SetUV(const AyLib::Rect& uv) {
		_uv = uv;
	}

	std::string Sprite::GetName() const {
		return _name;
	}

	const Resource::Image* Sprite::GetImage() const {
		return _image;
	}

	AyLib::Rect Sprite::GetUV() const {
		return _uv;
	}

	AyLib::Vector2 Sprite::GetPivot() const {
		return _pivot;
	}
}
