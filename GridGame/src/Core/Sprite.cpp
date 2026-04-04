#include "../../include/Sprite.hpp"

Sprite::Sprite(Image* image)
	: _name("")
	, _image(image)
	, _uv { 0.f, 0.f, 0.f, 0.f }
	, _pivot(Vector2(0.5f, 0.5f))
{
	if (_image) {
		_uv = Rect{
			0,
			0,
			_image->GetWidth(),
			_image->GetHeight()
		};
	}
}

Sprite::Sprite(Image* image, const Rect& rect)
	: _name("")
	, _image(image)
	, _uv(rect)
	, _pivot(Vector2(0.5f, 0.5f))
{}

Sprite::Sprite(Image * image, const Vector2 & vec)
	: _name("")
	, _image(image)
	, _uv{ 0, 0, 0, 0 }
	, _pivot(vec)
{
	if (_image) {
		_uv = Rect{
			0,
			0,
			_image->GetWidth(),
			_image->GetHeight()
		};
	}
}

Sprite::Sprite(Image* image, const Rect& rect, const Vector2& vec)
	: _name("")
	, _image(image)
	, _uv(rect)
	, _pivot(vec)
{}

void Sprite::SetUV(const Rect& uv) {
	_uv = uv;
}

std::string Sprite::GetName() const {
	return _name;
}

const Image* Sprite::GetImage() const {
	return _image;
}

Rect Sprite::GetUV() const {
	return _uv;
}

Vector2 Sprite::GetPivot() const {
	return _pivot;
}
