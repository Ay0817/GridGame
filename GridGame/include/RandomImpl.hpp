#pragma once

#include <cstdint>
#include <chrono>

namespace Internal {
    /// @brief 乱数生成の内部実装クラス
    class RandomImpl final {
    private:
        // xoroshiro128++ 定数
        static constexpr int ROTATE_A = 17;
        static constexpr int SHIFT_B = 9;
        static constexpr int ROTATE_C = 45;

        // splitmix64 定数
        static constexpr uint64_t SPLIT_MIX_GAMMA = 0x9e3779b97f4a7c15ULL;
        static constexpr uint64_t SPLIT_MIX_64_MULTIPLY_1 = 0xbf58476d1ce4e5b9ULL;
        static constexpr uint64_t SPLIT_MIX_64_MULTIPLY_2 = 0x94d049bb133111ebULL;

        static constexpr int SPLIT_MIX_64_SHIFT1 = 30;
        static constexpr int SPLIT_MIX_64_SHIFT2 = 27;
        static constexpr int SPLIT_MIX_64_SHIFT3 = 31;

        // float / double 用
        static constexpr int DOUBLE_SHIFT = 11; // 64 - 53
        static constexpr int FLOAT_SHIFT = 40;  // 64 - 24
        static constexpr int DOUBLE_BITS = 53;
        static constexpr int FLOAT_BITS = 24;
        uint64_t s[2]; // 内部状態
    private:
        /// @brief 左回転
        static constexpr uint64_t rotl(const uint64_t x, int k) {
            return (x << k) | (x >> (64 - k));
        }

        /// @brief splitmix64
        static uint64_t splitmix64(uint64_t& seed) {
            auto z = (seed += SPLIT_MIX_GAMMA);

            z = (z ^ (z >> SPLIT_MIX_64_SHIFT1)) * SPLIT_MIX_64_MULTIPLY_1;
            z = (z ^ (z >> SPLIT_MIX_64_SHIFT2)) * SPLIT_MIX_64_MULTIPLY_2;

            return z ^ (z >> SPLIT_MIX_64_SHIFT3);
        }
    public:
        /// @brief コンストラクタ
        /// @param seed シード値
        RandomImpl(uint64_t seed) {
            SetSeed(seed);
        }

        /// @brief シードを設定
        void SetSeed(uint64_t seed) {
            s[0] = splitmix64(seed);
            s[1] = splitmix64(seed);
        }

        /// @brief 64bit乱数生成
        /// @return 生成された乱数
        uint64_t Next64() noexcept {
            const auto reult = rotl(s[0] + s[1], ROTATE_A) + s[0];
            const auto t = s[1] << SHIFT_B;

            s[1] ^= s[0];
            s[0] ^= s[1];
            s[1] ^= s[0];

            s[0] ^= t;
            s[1] = rotl(s[1], ROTATE_C);

            return reult;
        }

        /// @brief 0 ～ max - 1
        int Next(int max) {
            if (max <= 0) {
                return 0;
            }

            auto m = static_cast<uint64_t>(max);
            auto t = (UINT64_MAX - m + 1) % m;

            for (;;) {
                auto r = Next64();

                if (r >= t) {
                    return static_cast<int>(r % m);
                }
            }
        }

        /// @brief 0 ～ 1
        float Nextfloat() {
            return (Next64() >> FLOAT_SHIFT) * (1.f / (1ULL << FLOAT_BITS));
        }

        /// @brief 0 ～ 1
        double NextDouble() {
            return (Next64() >> DOUBLE_SHIFT) * (1.0 / (1ULL << DOUBLE_BITS));
        }
    };

    /// @brief 乱数生成のグローバルインスタンス
    inline thread_local RandomImpl rng(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()
    );
}
