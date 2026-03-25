#pragma once

#include <cmath>
#include <concepts>
#include <utility>

/// @brief 整数型制約
template <typename T>
concept is_integral = std::is_integral_v<T>;

/// @brief 浮動小数点型制約
template <typename T>
concept is_floating = std::is_floating_point_v<T>;

/// @brief 数値型制約（整数型または浮動小数点型）
template <typename T>
concept is_numeric = std::is_integral_v<T> || std::is_floating_point_v<T>;

/// @brief ライブラリ全体で使用される数値計算・補間・三角関数・定数定義を提供する、静的ユーティリティ型の数学支援クラスです
class Math final {
private:
	Math() = delete;
public:
	// @brief 自然対数の底 e（定数）
	static constexpr float E = 2.71828175f;

	// @brief 円周率 π（定数）
	static constexpr float PI = 3.14159274f;

	// @brief 
	static constexpr float EPSILON = 1e-5f;

	// @brief 
	static constexpr float EPSILON_SQUARED = 1e-10f;

	// @brief 角度 f のサイン（正弦）を返す
	[[nodiscard]]
	static float Sin(float f) noexcept {
		return std::sin(f);
	}

	// @brief 角度 f のコサイン（余弦）を返す
	[[nodiscard]]
	static float Cos(float f) noexcept {
		return std::cos(f);
	}

	// @brief ラジアン単位の角度 f のタンジェント（正接）を返す
	[[nodiscard]]
	static float Tan(float f) noexcept {
		return std::tan(f);
	}

	// @brief f のアークサイン（逆正弦）を返す（戻り値はラジアン）
	[[nodiscard]]
	static float Asin(float f) noexcept {
		return std::asin(f);
	}

	// @brief f のアークコサイン（逆余弦）を返す（戻り値はラジアン）
	[[nodiscard]]
	static float Acos(float f) noexcept {
		return std::acos(f);
	}

	// @brief f のアークタンジェント（逆正接）を返す（戻り値はラジアン）
	[[nodiscard]]
	static float Atan(float f) noexcept {
		return std::atan(f);
	}

	// @brief y/x のアークタンジェント（逆正接）を返す（戻り値はラジアン）
	[[nodiscard]]
	static float Atan2(float y, float x) noexcept {
		return std::atan2(y, x);
	}

	// @brief f の平方根を返す
	[[nodiscard]]
	static float Sqrt(float f) noexcept {
		return std::sqrt(f);
	}

	// @brief float 型の絶対値を返す
	[[nodiscard]]
	static float Abs(float f) noexcept {
		return std::abs(f);
	}

	// @brief int 型の絶対値を返す
	[[nodiscard]]
	static int Abs(int value) noexcept {
		return std::abs(value);
	}

	// @brief
	[[nodiscard]]
	static float Sign(float f) noexcept {
		return (f >= 0.f) ? 1.f : (-1.f);
	}

	// @brief 2 つの値のうち小さい方を返す
	template <is_numeric T>
	[[nodiscard]]
	static constexpr T Min(T a, T b) noexcept {
		return (a < b) ? a : b;
	}

	// @brief 2 つの値のうち大きい方を返す
	template <is_numeric T>
	[[nodiscard]]
	static constexpr T Max(T a, T b) noexcept {
		return (a > b) ? a : b;
	}

	// @brief 
	template <is_numeric T>
	[[nodiscard]]
	static constexpr std::pair<T, T> MinMax(T a, T b) noexcept {
		if (a > b) {
			return { b,a };
		}
		return { a,b };
	}

	// @brief value を min と max の範囲内に収めて返す
	template <is_numeric T>
	[[nodiscard]]
	static constexpr T Clamp(T value, T min, T max) noexcept {
		if (value < min) {
			value = min;
		}
		else if (value > max) {
			value = max;
		}
		return value;
	}

	// @brief value を 0～1 の範囲に制限して返す
	[[nodiscard]]
	static constexpr float Clamp01(float value) noexcept {
		if (value < 0.f) {
			return 0.f;
		}
		if (value > 1.f) {
			return 1.f;
		}
		return value;
	}

	// @brief a から b への線形補間（t を 0～1 に制限）
	[[nodiscard]]
	static constexpr float Lerp(float a, float b, float t) noexcept {
		return a + (b - a) * Clamp01(t);
	}

	// @brief a から b への線形補間（t の範囲は制限しない）
	[[nodiscard]]
	static constexpr float LerpUnclamped(float a, float b, float t) noexcept {
		return a + (b - a) * t;
	}
};
