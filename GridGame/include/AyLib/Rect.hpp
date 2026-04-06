#pragma once

#include "Vector2.hpp"

namespace AyLib 
{
    /// @brief é≤Ç…ïΩçsÇ»ãÈå`
    struct Rect {
        float x;
        float y;
        float w;
        float h;

        /// @brief ç∂
        [[nodiscard]]
        constexpr float Left() const noexcept {
            return x;
        }

        /// @brief âE
        [[nodiscard]]
        constexpr float Right() const noexcept {
            return x + w;
        }

        /// @brief è„
        [[nodiscard]]
        constexpr float Top() const noexcept {
            return y;
        }

        /// @brief â∫
        [[nodiscard]]
        constexpr float Bottom() const noexcept {
            return y + h;
        }

        /// @brief â°
        [[nodiscard]]
        constexpr float Width() const noexcept {
            return w;
        }

        /// @brief èc
        [[nodiscard]]
        constexpr float Height() const noexcept {
            return h;
        }

        /// @brief íÜâõ
        [[nodiscard]]
        constexpr Vector2 Center() const noexcept {
            return { x + w * 0.5f, y + h * 0.5f };
        }

        /// @brief îªíË
        [[nodiscard]]
        constexpr bool Contains(float px, float py) const noexcept {
            return px >= Left() && px <= Right() && py >= Top() && py <= Bottom();
        }

        /// @brief îªíË
        [[nodiscard]]
        constexpr bool Contains(const Vector2& p) const noexcept {
            return Contains(p.x, p.y);
        }

        /// @brief åç∑îªíË
        [[nodiscard]]
        constexpr bool Intersects(const Rect& other) const noexcept {
            return !(Right() < other.Left() || Left() > other.Right() || Bottom() < other.Top() || Top() > other.Bottom());
        }

        /// @brief ê≥ãKâª
        [[nodiscard]]
        constexpr Rect Normalized() const noexcept {
            auto r = *this;

            if (r.w < 0) {
                r.x += r.w; r.w = -r.w; 
            }

            if (r.h < 0) {
                r.y += r.h; r.h = -r.h; 
            }

            return r;
        }
    };
}
