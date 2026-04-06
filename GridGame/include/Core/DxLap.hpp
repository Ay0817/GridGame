#pragma once

#include <string>
#include <string_view>
#include <utility>

#include "AyLib/Color.hpp"
#include "AyLib/Palette.hpp"
#include "AyLib/Vector2.hpp"

namespace Core::DxLap 
{
	/// @brief 初期化用の設定
	class Config {
	public:
		std::string title = "DxLap App"; // タイトル
		bool windowMode = true;          // Windowにするか？
		bool alwaysRun = true;           // 非アクティブ時も動かすか？

		int width = 1280; // 横幅(default:1280)
		int height = 720; // 縦幅(default:720)

		bool enableLog = false; // ログを有効にするか？

		AyLib::Color bgColor = AyLib::Palette::Basic::White; // 背景色(default:白)
	public:
		/// @brief タイトルを設定
		Config& SetTitle(std::string_view titleName)&;

		/// @brief タイトルを設定(右辺値)
		Config&& SetTitle(std::string_view titleName)&&;

		/// @brief ウィンドウモードを設定
		Config& SetWindowMode(bool enable)&;

		/// @brief ウィンドウモードを設定(右辺値)
		Config&& SetWindowMode(bool enable)&&;

		/// @brief 非アクティブ状態でも処理を実行するかどうかを設定
		Config& SetAlwaysRun(bool enable)&;

		/// @brief 非アクティブ状態でも処理を実行するかどうかを設定(右辺値)
		Config&& SetAlwaysRun(bool enable)&&;

		/// @brief ウィンドウサイズを設定
		Config& SetWindowSize(int w, int h)&;

		/// @brief ウィンドウサイズを設定(右辺値)
		Config&& SetWindowSize(int w, int h)&&;

		/// @brief ログを有効にするかどうかを設定
		Config& EnableLog(bool enable)&;

		/// @brief ログを有効にするかどうかを設定(右辺値)
		Config&& EnableLog(bool enable)&&;

		/// @brief 背景色を設定
		Config& SetBackground(int r, int g, int b, int a)&;

		/// @brief 背景色を設定(右辺値)
		Config&& SetBackground(int r, int g, int b, int a)&&;

		/// @brief 背景色を設定
		Config& SetBackground(const AyLib::Color& color)&;

		/// @brief 背景色を設定(右辺値)
		Config&& SetBackground(const AyLib::Color& color)&&;
	};

	/// @brief DxLibの初期化
	[[nodiscard]]
	bool Init(const Config& config);

	/// @brief ウィンドウ関連
	namespace Window {
		/// @brief タイトルを設定
		void SetTitle(const std::string& titleName);

		/// @brief タイトルを設定
		void SetTitle(std::string_view titleName);

		/// @brief ウィンドウモードを設定
		void SetWindowMode(bool enable);

		/// @brief 非アクティブ状態でも処理を実行するかどうかを設定
		void SetAlwaysRun(bool enable);

		/// @brief ウィンドウサイズを設定
		void SetSize(int width, int height);

		/// @brief ウィンドウサイズを取得
		[[nodiscard]]
		AyLib::Vector2 GetSizeF();

		/// @brief ウィンドウサイズを取得
		[[nodiscard]]
		std::pair<int, int> GetSize();
	}

	/// @brief 画面関連
	namespace Screen {
		/// @brief 解像度を設定
		void SetResolution(int width, int height, int colorBit = 32);

		/// @brief 背景色を設定
		void SetBgColor(const AyLib::Color& color);
	}

	/// @brief システム関連
	namespace System {
		/// @brief ログを有効にするかどうかを設定
		void EnableLog(bool enable);
	}
}

using namespace Core::DxLap;
