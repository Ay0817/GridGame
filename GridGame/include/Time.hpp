#pragma once

/// @brief 時間管理クラス
class Time final {
private:
	Time() = delete;
public:
	/// @brief 現在のゲーム全体の経過時間を取得
	/// @return 経過時間
	[[nodiscard]]
	static float GetTime();

	/// @brief 現在のゲーム全体のスケールを考慮しない経過時間を取得
	/// @return 経過時間
	[[nodiscard]]
	static float GetUnscaledTime();

	/// @brief 直前のフレームから現在のフレームまでの時間差分を取得
	/// @return 時間差分
	[[nodiscard]]
	static float GetDeltaTime();

	/// @brief 直前のフレームから現在のフレームまでのスケールを考慮しない時間差分を取得
	/// @return 時間差分
	[[nodiscard]]
	static float GetUnscaledDeltaTime();

	/// @brief 時間スケールを設定
	/// @param scale 時間スケール(デフォルト値は 1.0f)
	static void SetScale(float scale = 1.0f);
};
