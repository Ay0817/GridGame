#pragma once

#include "Math.hpp"

 /// @brief RGBAカラーを表す構造体
struct Color {
    // @brief red
    unsigned int r;

    // @brief green
    unsigned int g;

    // @brief blue
    unsigned int b;

    // @brief alpha
    unsigned int a;

    // @brief 最小値
    static constexpr unsigned int MIN = 0;

    // @brief 最大値
    static constexpr unsigned int MAX = 255;

    // @brief コンストラクタ
    [[nodiscard]]
    Color() noexcept = default;

    // @brief コンストラクタ
    [[nodiscard]]
    Color(const Color&) noexcept = default;

    // @brief コンストラクタ
    [[nodiscard]]
    constexpr explicit Color(unsigned int r, unsigned int g, unsigned int b, unsigned int a) noexcept 
        : r(Math::Clamp(r, MIN, MAX))
        , g(Math::Clamp(g, MIN, MAX))
        , b(Math::Clamp(b, MIN, MAX))
        , a(Math::Clamp(a, MIN, MAX)) 
    {}

    // @brief デストラクタ
    constexpr ~Color() noexcept = default;

    // @brief コピー代入演算子
    constexpr Color& operator = (const Color&) = default;

    // @brief 要素を設定
    void Set(unsigned int _r, unsigned int _g, unsigned int _b, unsigned int _a) noexcept {
        r = Math::Clamp(r, MIN, MAX);
        g = Math::Clamp(g, MIN, MAX);
        b = Math::Clamp(b, MIN, MAX);
        a = Math::Clamp(a, MIN, MAX);
    }

    // @brief 16進にして返す
    [[nodiscard]]
    constexpr unsigned int ToUInt() const noexcept {
        return (r << 16) | (g << 8) | b;
    }
};
