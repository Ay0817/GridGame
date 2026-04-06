#pragma once

#include <cstdint>
#include <string_view>

namespace AyLib::Hash
{
	inline constexpr uint32_t FNV_OFFSET_BASIS_32 = 2166136261u;
	inline constexpr uint64_t FNV_OFFSET_BASIS_64 = 14695981039346656037u;

	inline constexpr uint32_t FNV_PRIME_32 = 16777619u;
	inline constexpr uint64_t FNV_PRIME_64 = 1099511628211llu;

	/// @brief FNV-1aハッシュの共通化 Template 関数
	/// @tparam T ハッシュ値の型
	/// @tparam Offset オフセット値
	/// @tparam Prime 素数値
	/// @param str ハッシュ化する文字列
	/// @return ハッシュ値
	template <typename T, T Offset, T Prime>
		requires std::is_unsigned<T>::value
	[[nodiscard]]
		inline constexpr auto FNV1a(std::string_view str) noexcept {
		T hash = Offset;

		for (unsigned char c : str) {
			hash ^= c;
			hash *= Prime;
		}

		return hash;
	}

	/// @brief FNV-1aハッシュ（32ビット版）
	/// @param str ハッシュ化する文字列
	/// @return ハッシュ値
	[[nodiscard]]
	inline constexpr uint32_t FNV1a_32(std::string_view str) noexcept {
		return FNV1a<uint32_t, FNV_OFFSET_BASIS_32, FNV_PRIME_32>(str);
	}

	/// @brief FNV-1aハッシュ（64ビット版）
	/// @param str ハッシュ化する文字列
	/// @return ハッシュ値
	[[nodiscard]]
	inline constexpr uint64_t FNV1a_64(std::string_view str) noexcept {
		return FNV1a<uint64_t, FNV_OFFSET_BASIS_64, FNV_PRIME_64>(str);
	}

	/// @brief ユーザー定義リテラル（32ビット版）
	/// @param str ハッシュ化する文字列
	/// @return ハッシュ値
	[[nodiscard]]
	inline constexpr uint32_t operator"" _h32(const char* str, size_t) noexcept {
		return FNV1a_32(str);
	}

	/// @brief ユーザー定義リテラル（64ビット版）
	/// @param str ハッシュ化する文字列
	/// @return ハッシュ値
	[[nodiscard]]
	inline constexpr uint64_t operator"" _h64(const char* str, size_t) noexcept {
		return FNV1a_64(str);
	}

#ifdef AY_DEBUG
	/// @brief 名前付きハッシュ構造体（デバッグ用）
	/// @tparam T ハッシュ値の型
	template <typename T>
	struct NamedHash {
		T hash;
		const char* name;
	};

	/// @brief 名前付きハッシュを作成する（32ビット版）
	/// @param str ハッシュ化する文字列
	/// @return 名前付きハッシュ
	[[nodiscard]]
	inline constexpr NamedHash<uint32_t> MakeHash_32(const char* str) noexcept {
		return { FNV1a_32(str), str };
	}

	/// @brief 名前付きハッシュを作成する（64ビット版）
	/// @param str ハッシュ化する文字列
	/// @return 名前付きハッシュ
	[[nodiscard]]
	inline constexpr NamedHash<uint64_t> MakeHash_64(const char* str) noexcept {
		return { FNV1a_64(str), str };
	}

#else 
	/// @brief 名前付きハッシュを作成する
	/// @param str ハッシュ化する文字列
	/// @return ハッシュ値
	[[nodiscard]]
	inline constexpr uint32_t MakeHash_32(const char* str) noexcept {
		return FNV1a_32(str);
	}

	/// @brief 名前付きハッシュを作成する
	/// @param str ハッシュ化する文字列
	/// @return ハッシュ値
	[[nodiscard]]
	inline constexpr uint64_t MakeHash_64(const char* str) noexcept {
		return FNV1a_64(str);
	}
#endif
}
