#include <DxLib.h>
#include <cassert>

#include "../../include/Font.hpp"

Font::Font(std::string_view name, std::string_view path, const FontInfo& fontInfo)
	: Asset(std::string(name))
	, _path(std::string(path))
	, _fontInfo(fontInfo)
{
	if (_handle == -1) {
		auto src = AddFontResourceExA(path.data(), FR_PRIVATE, NULL);

		assert(src != 0);

		_handle = CreateFontToHandle(name.data(), _fontInfo.size, _fontInfo.thick, _fontInfo.type);

		assert(_handle != -1);
	}
}

Font::~Font() {
	Release();
}

void Font::Release() {
	if (_handle != -1) {
		DeleteFontToHandle(_handle);
		RemoveFontResourceExA(_path.data(), FR_PRIVATE, NULL);
	}
}
