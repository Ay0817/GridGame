#pragma once

/// @brief 内部で使用される時間管理クラス
class TimeImpl final {
private:
	friend class Time; // Time クラスが TimeSystem のプライベートメンバにアクセスできるようにする
private:
	TimeImpl() = delete;

	static double time;          // 経過時間
	static double unscaledTime;  // スケール適用前の経過時間
	static double delta;         // デルタ時間
	static double unscaledDelta; // スケール適用前のデルタ時間
	static float  scale;         // 時間スケール
public:
	/// @brief 初期化処理
	static void Init();

	/// @brief 更新処理
	static void Update();
};
