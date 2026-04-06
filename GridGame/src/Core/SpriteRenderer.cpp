#include <DxLib.h>

#include <Core/SpriteRenderer.hpp>
#include <Core/GameObject.hpp>

namespace Core
{
	SpriteRenderer::SpriteRenderer(const UI::Sprite& sprite, int order, int layer)
        : Renderer(layer, order)
        , _sprite(sprite)
        , _transform(nullptr)
    {}

    void SpriteRenderer::Begin() {
        auto owner = GetOwner();

        _transform = &owner->GetTransform();
    }

    void SpriteRenderer::Draw() const {
        if (!_transform) {
            return;
        }

        auto [x, y] = _transform->position;
        auto [sx, sy] = _transform->scale;
        auto angle = _transform->angle;

        auto image = _sprite.GetImage();
        auto [ux, uy, uw, uh] = _sprite.GetUV();
        auto [px, py] = _sprite.GetPivot();

        auto handle = image->GetHandle();

        auto cx = px * uw;
        auto cy = py * uh;

        DxLib::DrawRectRotaGraph3F(
            x, y,
            static_cast<int>(ux), static_cast<int>(uy),
            static_cast<int>(uw), static_cast<int>(uh),
            cx, cy,
            sx, sy,
            angle,
            handle,
            true
        );
    }

    UI::Sprite& SpriteRenderer::GetSprite() {
        return _sprite;
    }
}
