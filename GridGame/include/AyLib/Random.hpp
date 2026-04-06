#pragma once

#include <algorithm>

#include "RandomImpl.hpp"

namespace AyLib
{
	class Random final {
	public:
		/// @brief 初期化処理
		/// @param seed シード値
		static void Init(uint64_t seed) {
			Internal::rng.SetSeed(seed);
		}

		/// @brief 乱数を生成 [0, max - 1]
		[[nodiscard]]
		static int Next(int max) {
			return Internal::rng.Next(max);
		}

		/// @brief 乱数を生成 [0, 1]
		[[nodiscard]]
		static float Value() {
			return Internal::rng.Nextfloat();
		}

		/// @brief 乱数を生成 [0, 1]
		[[nodiscard]]
		static double ValueDouble() {
			return Internal::rng.NextDouble();
		}

		/// @brief 乱数を生成 [min, max]
		[[nodiscard]]
		static int Range(int min, int max) {
			if (max <= min) {
				return min;
			}

			return min + Next(max - min);
		}

		/// @brief 乱数を生成 [min, max]
		[[nodiscard]]
		static float Range(float min, float max) {
			if (max <= min) {
				return min;
			}

			return min + (max - min) * Value();
		}

		/// @brief 乱数を生成 [min, max]
		[[nodiscard]]
		static double Range(double min, double max) {
			if (max <= min) {
				return min;
			}

			return min + (max - min) * ValueDouble();
		}

		/// @brief 確率に基づいて true / false を返す
		[[nodiscard]]
		static bool Chance(float probability = 0.5f) {
			return Value() < probability;
		}

		/// @brief 配列シャッフル
		template<typename T>
		static void Shuffle(std::vector<T>& vec) {
			for (auto i = static_cast<int>(vec.size()) - 1; i > 0; --i) {
				auto j = Next(i + 1);
				std::swap(vec[i], vec[j]);
			}
		}
	};
}
