#pragma once

#include <cstdint>

 /// @brief RGBAカラーを表す構造体
struct Color {
    // @brief red
    uint8_t r = 0;

    // @brief green
    uint8_t g = 0;

    // @brief blue
    uint8_t b = 0;

    // @brief alpha
    uint8_t a = 255;

    // @brief 最小値
    static constexpr uint8_t MIN = 0;

    // @brief 最大値
    static constexpr uint8_t MAX = 255;
private:
    /// @brief Clamp
    static constexpr uint8_t ClampByte(uint32_t v) noexcept {
        return static_cast<uint8_t>(v > MAX ? MAX : v);
    }
public:
    /// @brief デフォルトコンストラクタ
    Color() noexcept = default;

    // @brief コピーコンストラクタ
    [[nodiscard]]
    Color(const Color&) noexcept = default;

    // @brief コンストラクタ
    [[nodiscard]]
    constexpr explicit Color(uint32_t r, uint32_t  g, uint32_t  b, uint32_t  a = 255) noexcept
        : r(ClampByte(r))
        , g(ClampByte(g))
        , b(ClampByte(b))
        , a(ClampByte(a))
    {}

    // @brief デストラクタ
    constexpr ~Color() noexcept = default;

    // @brief コピー代入演算子
    constexpr Color& operator = (const Color&) = default;

    // @brief 要素を設定
    void Set(uint32_t _r, uint32_t _g, uint32_t _b, uint32_t _a = 255) noexcept {
        r = ClampByte(_r);
        g = ClampByte(_g);
        b = ClampByte(_b);
        a = ClampByte(_a);
    }

    // @brief 16進にして返す
    [[nodiscard]]
    constexpr unsigned int ToRGB() const noexcept {
        return (static_cast<uint32_t>(r) << 16) | (static_cast<uint32_t>(g) << 8) | static_cast<uint32_t>(b);
    }
};
