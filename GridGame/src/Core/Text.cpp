#include <DxLib.h>

#include "../../include/Text.hpp"
#include "../../include/GameObject.hpp"

Text::Text(const TextInfo& textInfo)
	: Component()
	, _textInfo(textInfo)
{}

int Text::GetAlignedX(int baseX, int textWidth) const {
    switch (_textInfo.textAlign.horizontal) {
    case HorizontalAlign::Left:
        return baseX;

    case HorizontalAlign::Mid:
        return baseX - textWidth / 2;

    case HorizontalAlign::Right:
        return baseX - textWidth;

    default:
        return baseX;
    }
}

int Text::GetAlignedY(int baseY, int textHeight) const {
    switch (_textInfo.textAlign.vertical) {
    case VerticalAlign::Top:
        return baseY;

    case VerticalAlign::Mid:
        return baseY - textHeight / 2;

    case VerticalAlign::Bot:
        return baseY - textHeight;

    default:
        return baseY;
    }
}

void Text::Begin() {
    _transformCached = &GetOwner()->GetTransform();
}

void Text::Draw() const {
    auto transform = _transformCached;
    auto handle = _textInfo.font->GetHandle();

    auto w = GetDrawStringWidthToHandle(_textInfo.text.data(), static_cast<int>(_textInfo.text.size()), handle);
    auto h = GetFontSizeToHandle(handle);

    auto x = GetAlignedX(static_cast<int>(transform->position.x), w);
    auto y = GetAlignedY(static_cast<int>(transform->position.y), h);


    SetDrawBlendMode(DX_BLENDMODE_ALPHA, _textInfo.color.a);
    DrawStringToHandle(x, y, _textInfo.text.data(), _textInfo.color.ToRGB(), handle);
    SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
}

void Text::SetText(const std::string& text) {
	_textInfo.text = text;
}

void Text::SetColor(const Color& color) {
	_textInfo.color = color;
}

Color Text::GetColor() const {
    return _textInfo.color;
}
