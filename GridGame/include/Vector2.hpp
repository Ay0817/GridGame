#pragma once

#include <cmath>

#include "Math.hpp"

/// @brief 2次元ベクトルを表す構造体
struct Vector2 {

    // @brief x 座標
    float x = 0.f;

    // @brief y 座標
    float y = 0.f;

    // @brief デフォルトコンストラクタ
    constexpr Vector2() noexcept = default;

    // @brief コンストラクタ
    constexpr Vector2(float _x, float _y) noexcept : x(_x), y(_y) {}

    // @brief 単項 - 演算子
    constexpr Vector2 operator -() const noexcept {
        return Vector2(-x, -y);
    }

    // @brief + 演算子
    constexpr Vector2 operator +(const Vector2& other) const noexcept {
        return Vector2(x + other.x, y + other.y);
    }

    // @brief - 演算子
    constexpr Vector2 operator -(const Vector2& other) const noexcept {
        return Vector2(x - other.x, y - other.y);
    }

    // @brief * 演算子(スカラー倍)
    constexpr Vector2 operator *(float scalar) const noexcept {
        return Vector2(x * scalar, y * scalar);
    }

    // @brief / 演算子(スカラー除算)
    constexpr Vector2 operator /(float scalar) const noexcept {
        return Vector2(x / scalar, y / scalar);
    }

    // @brief += 演算子
    constexpr Vector2& operator +=(const Vector2& other) noexcept {
        x += other.x;
        y += other.y;
        return *this;
    }

    // @brief -= 演算子
    constexpr Vector2& operator -=(const Vector2& other) noexcept {
        x -= other.x;
        y -= other.y;
        return *this;
    }

    // @brief *= 演算子(スカラー倍)
    constexpr Vector2& operator *=(float scalar) noexcept {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    // @brief /= 演算子(スカラー除算)
    constexpr Vector2& operator /=(float scalar) noexcept {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    // @brief == 演算子
    constexpr bool operator ==(const Vector2& other) const noexcept {
        float dx = x - other.x;
        float dy = y - other.y;
        return (dx * dx + dy * dy) < Math::EPSILON_SQUARED;
    }

    // @brief != 演算子
    constexpr bool operator !=(const Vector2& other) const noexcept {
        return !(*this == other);
    }

    /// @brief 値を設定する
    /// @param _x x 値
    /// @param _y y 値
    constexpr void Set(float _x, float _y) noexcept {
        x = _x;
        y = _y;
    }

    /// @brief ベクトルの長さを返す
    /// @return 長さを返す
    [[nodiscard]]
    float Length() const noexcept {
        return Math::Sqrt(x * x + y * y);
    }

    /// @brief ベクトルの二乗の長さを返す
    /// @return 二乗の長さを返す
    [[nodiscard]]
    constexpr float LengthSq() const noexcept {
        return x * x + y * y;
    }

    /// @brief ベクトルがゼロか判定
    /// @return true = ほぼゼロ
    [[nodiscard]]
    constexpr bool IsZero() const noexcept {
        return LengthSq() < Math::EPSILON_SQUARED;
    }

    /// @brief 自身のベクトルを正規化する
    void Normalize() noexcept {
        float len = Length();
        if (len > Math::EPSILON) {
            *this /= len;
        }
    }

    /// @brief 安全な正規化(ゼロベクトル対応)
    [[nodiscard]]
    static Vector2 SafeNormalize(const Vector2& v) noexcept {
        float len = v.Length();
        return (len > Math::EPSILON) ? v / len : zero();
    }

    /// @brief 指定ベクトルを正規化する
    [[nodiscard]]
    static Vector2 Normalize(const Vector2& v) noexcept {
        return SafeNormalize(v);
    }

    /// @brief 内積を返す
    [[nodiscard]]
    static constexpr float Dot(const Vector2& a, const Vector2& b) noexcept {
        return a.x * b.x + a.y * b.y;
    }

    /// @brief 外積を返す
    [[nodiscard]]
    static constexpr float Cross(const Vector2& a, const Vector2& b) noexcept {
        return a.x * b.y - a.y * b.x;
    }

    /// @brief 2点間の距離を計算する
    [[nodiscard]]
    static float Distance(const Vector2& a, const Vector2& b) noexcept {
        return (a - b).Length();
    }

    /// @brief 線形補間
    [[nodiscard]]
    static Vector2 Lerp(const Vector2& a, const Vector2& b, float t) noexcept {
        t = Math::Clamp01(t);
        return a + (b - a) * t;
    }

    /// @brief 制限なし線形補間
    [[nodiscard]]
    static constexpr Vector2 LerpUnclamped(const Vector2& a, const Vector2& b, float t) noexcept {
        return a + (b - a) * t;
    }

    /// @brief 指定距離以内で目標に近づける
    [[nodiscard]]
    static Vector2 MoveTowards(const Vector2& current, const Vector2& target, float maxDistanceDelta) noexcept {
        Vector2 diff = target - current;
        float dist = diff.Length();

        if (dist <= maxDistanceDelta || dist == 0.f) {
            return target;
        }

        return current + diff / dist * maxDistanceDelta;
    }

    /// @brief ベクトルの長さを制限する
    [[nodiscard]]
    static Vector2 ClampMagnitude(const Vector2& v, float maxLength) noexcept {
        float lenSq = v.LengthSq();
        if (lenSq > maxLength * maxLength) {
            float len = Math::Sqrt(lenSq);
            return v / len * maxLength;
        }
        return v;
    }

    /// @brief 要素ごとのスケーリング
    [[nodiscard]]
    static constexpr Vector2 Scale(const Vector2& a, const Vector2& b) noexcept {
        return Vector2(a.x * b.x, a.y * b.y);
    }

    /// @return {0.f, 0.f}
    [[nodiscard]]
    static constexpr Vector2 zero() noexcept {
        return Vector2(0.f, 0.f);
    }

    /// @return {1.f, 1.f}
    [[nodiscard]]
    static constexpr Vector2 one() noexcept {
        return Vector2(1.f, 1.f);
    }

    /// @return {0.f, -1.f}
    [[nodiscard]]
    static constexpr Vector2 up() noexcept {
        return Vector2(0.f, -1.f);
    }

    /// @return {0.f, 1.f}
    [[nodiscard]]
    static constexpr Vector2 down() noexcept {
        return Vector2(0.f, 1.f);
    }

    /// @return {1.f, 0.f}
    [[nodiscard]]
    static constexpr Vector2 right() noexcept {
        return Vector2(1.f, 0.f);
    }

    /// @return {-1.f, 0.f}
    [[nodiscard]]
    static constexpr Vector2 left() noexcept {
        return Vector2(-1.f, 0.f);
    }
};
