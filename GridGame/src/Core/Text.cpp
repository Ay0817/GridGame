#include <DxLib.h>

#include "../../include/Text.hpp"
#include "../../include/GameObject.hpp"

Text::Text(const TextInfo& textInfo)
	: Component()
	, _textInfo(textInfo)
{}

int Text::GetAlignedX(int baseX, int textWidth) const {
    switch (_textInfo.textAlign) {
    case TextAlign::Left:
        return baseX;

    case TextAlign::Center:
        return baseX - textWidth / 2;

    case TextAlign::Right:
        return baseX - textWidth;

    default:
        return baseX;
    }
}

void Text::Begin() {
    _transformCached = &GetOwner()->GetTransform();
}

void Text::Draw() const {
    auto transform = _transformCached;
    auto handle = _textInfo.font->GetHandle();

    auto w = GetDrawStringWidthToHandle(_textInfo.text.data(), static_cast<int>(_textInfo.text.size()), handle);

    auto x = GetAlignedX(static_cast<int>(transform->position.x), w);
    auto y = static_cast<int>(transform->position.y);

    DrawStringToHandle(x, y, _textInfo.text.data(), _textInfo.color.ToUInt(), handle);
}

void Text::SetText(const std::string& text) {
	_textInfo.text = text;
}
