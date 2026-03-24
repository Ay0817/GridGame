/******************************************************************************
 * @file    Input.hpp
 * @brief   入力（キーボードおよびマウス）の状態をフレーム単位で取得するための、ライブラリ入力管理クラスです。
 * @author  Ay
 * @date    2026/01/10
 * @par
 * Copyright (c) 2026 AyLib
 ******************************************************************************/

#pragma once

#include <utility>

namespace AyLib
{
	// @brief キーボード入力としてライブラリが対応しているキーコードを定義し、入力システム全体で共通に使用されるキー列挙型です。
	enum class Keys : uint8_t {
		A = 0x1e,
		B = 0x30,
		C = 0x2e,
		D = 0x20,
		E = 0x12,
		F = 0x21,
		G = 0x22,
		H = 0x23,
		I = 0x17,
		J = 0x24,
		K = 0x25,
		L = 0x26,
		M = 0x32,
		N = 0x31,
		O = 0x18,
		P = 0x19,
		Q = 0x10,
		R = 0x13,
		S = 0x1f,
		T = 0x14,
		U = 0x16,
		V = 0x2f,
		W = 0x11,
		X = 0x2d,
		Y = 0x15,
		Z = 0x2c,

		Alpha1 = 0x02,
		Alpha2 = 0x03,
		Alpha3 = 0x04,
		Alpha4 = 0x05,
		Alpha5 = 0x06,
		Alpha6 = 0x07,
		Alpha7 = 0x08,
		Alpha8 = 0x09,
		Alpha9 = 0x0a,
		Alpha0 = 0x0b,

		ESC = 0x01,
		SPACE = 0x39,
		LSHIT = 0x2a,
		RSHIT = 0x36,
		ENTER = 0x1c,

		UpArrow = 0xc8,
		DownArrow = 0xd0,
		RightArrow = 0xcd,
		LeftArrow = 0xcb,
	};

	/// @brief ライブラリの入力システムで使用される、対応済みマウスボタン種別を定義した列挙型です。
	enum class MouseButtons : uint8_t {
		Left = 0,
		Right,
		Mid
	};

	/// @brief 入力（キーボードおよびマウス）の状態をフレーム単位で取得するための、ライブラリ入力管理クラス
	class Input final {
	private:
		Input() = delete;
	public:
		// @param key 押されているか確認したいキー
		// @return キーを押している間、true を返す
		[[nodiscard]]
		static bool GetKey(Keys key);

		// @param key 押されているか確認したいキー
		// @return キーを押したフレームの間だけ、true を返す
		[[nodiscard]]
		static bool GetKeyDown(Keys key);

		// @param key 押されているか確認したいキー
		// @return キーを離したフレームの間だけ、true を返す
		[[nodiscard]]
		static bool GetKeyUp(Keys key);

		// @param button 押されているか確認したいボタン
		// @return マウスボタンが押されているかどうかを返す
		[[nodiscard]]
		static bool GetMouseButton(MouseButtons button);

		// @param button 押されているか確認したいボタン
		// @return マウスボタンを押したフレームの間だけ true を返す
		[[nodiscard]]
		static bool GetMouseButtonDown(MouseButtons button);

		// @param button 押されているか確認したいボタン
		// @return マウスボタンを離したフレームの間だけ true を返す
		[[nodiscard]]
		static bool GetMouseButtonUp(MouseButtons button);

		// @return 現在のマウスカーソル座標を返す
		[[nodiscard]]
		static std::pair<int, int> GetMousePosition();

		// @return マウスカーソル座標の移動量を返す
		[[nodiscard]]
		static std::pair<int, int> GetMouseDelta();
	};
}
