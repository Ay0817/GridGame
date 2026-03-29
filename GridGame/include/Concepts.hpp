#pragma once

#include <concepts>

namespace Concept {
    /// @brief ®”Œ^§–ñ
    template <typename T>
    concept is_integral = std::is_integral_v<T>;

    /// @brief •‚“®¬”“_Œ^§–ñ
    template <typename T>
    concept is_floating = std::is_floating_point_v<T>;

    /// @brief ”’lŒ^§–ñ
    template <typename T>
    concept is_numeric = is_integral<T> || is_floating<T>;

    /// @brief 
    template <typename T>
    concept is_signed = std::is_signed_v<T>;

    /// @brief 
    template <typename T>
    concept is_unsigned = !std::is_signed_v<T>;

    /// @brief 
    template <typename T>
    concept is_signed_numeric = is_numeric<T> && is_signed<T>;

    /// @brief 
    template <typename T>
    concept is_unsigned_numeric = is_numeric<T> && is_unsigned<T>;

    /// @brief 
    template <typename T>
    concept is_ptr = std::is_pointer_v<T>;
}
 