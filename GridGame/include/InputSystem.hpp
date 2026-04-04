#pragma once

#include <array>
#include <utility>

#include "Vector2.hpp"

 /// @brief キーボードおよびマウス入力の内部状態を管理し、フレームごとの入力遷移を更新するためのエンジン内部用入力管理クラスです。
class InputSystem final {
private:
	friend class Input; // Input クラスからのみアクセス可能にする
private:
	/// @brief 入力状態を表す列挙型
	enum class State : uint8_t {
		RELEASE = 0, // 入力されていない
		PRESSING,    // 入力された瞬間
		PRESS,       // 入力されている
		RELEASING    // 離された瞬間
	};

	static std::array<State, 256> keyInputs; // キーボード入力状態配列
	static std::array<State, 3> mouseInputs; // マウス入力状態配列

	static Vector2 position; // マウスカーソル座標
	static Vector2 delta;    // マウスカーソル座標の移動量

	InputSystem() = delete;

	/// @brief 現在の状態と押下情報から次の状態を取得します。
	/// @param current 現在の状態
	/// @param pressd 押されているかどうか
	/// @return 次の状態
	[[nodiscard]]
	static State NextState(State current, bool pressd) noexcept;
public:
	/// @brief 更新処理
	static void Update();

	/// @brief 終了処理
	static void End();
};
