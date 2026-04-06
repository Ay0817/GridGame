#include <DxLib.h>

#include <Core/DxLap.hpp>

namespace Core::DxLap 
{
	Config& Config::SetTitle(std::string_view titleName)& {
		title = std::string(titleName);

		return *this;
	}

	Config&& Config::SetTitle(std::string_view titleName)&& {
		title = std::string(titleName);

		return std::move(*this);
	}

	Config& Config::SetWindowMode(bool enable)& {
		windowMode = enable;

		return *this;
	}

	Config&& Config::SetWindowMode(bool enable)&& {
		windowMode = enable;

		return std::move(*this);
	}

	Config& Config::SetAlwaysRun(bool enable)& {
		alwaysRun = enable;

		return *this;
	}

	Config&& Config::SetAlwaysRun(bool enable)&& {
		alwaysRun = enable;

		return std::move(*this);
	}

	Config& Config::SetWindowSize(int w, int h)& {
		width = w;
		height = h;

		return *this;
	}

	Config&& Config::SetWindowSize(int w, int h)&& {
		width = w;
		height = h;

		return std::move(*this);
	}

	Config& Config::EnableLog(bool enable)& {
		enableLog = enable;

		return *this;
	}

	Config&& Config::EnableLog(bool enable)&& {
		enableLog = enable;

		return std::move(*this);
	}

	Config& Config::SetBackground(int r, int g, int b, int a)& {
		bgColor = AyLib::Color(r, g, b, a);

		return *this;
	}

	Config&& Config::SetBackground(int r, int g, int b, int a)&& {
		bgColor = AyLib::Color(r, g, b, a);

		return std::move(*this);
	}

	Config& Config::SetBackground(const AyLib::Color& color)& {
		bgColor = color;

		return *this;
	}

	Config&& Config::SetBackground(const AyLib::Color& color)&& {
		bgColor = color;

		return std::move(*this);
	}

	bool Init(const Config& config) {
		// System
		DxLib::SetOutApplicationLogValidFlag(config.enableLog);

		// Window
		DxLib::SetAlwaysRunFlag(config.alwaysRun);
		DxLib::ChangeWindowMode(config.windowMode);
		DxLib::SetWindowTextDX(config.title.c_str());

		// Screen
		DxLib::SetGraphMode(config.width, config.height, 32);
		DxLib::SetWindowSize(config.width, config.height);

		// Background
		DxLib::SetBackgroundColor(
			config.bgColor.r,
			config.bgColor.g,
			config.bgColor.b,
			config.bgColor.a
		);

		// èâä˙âª
		if (DxLib::DxLib_Init() == -1) {
			return false;
		}

		// ï`âÊêÊÇó†âÊñ Ç…ê›íË
		DxLib::SetDrawScreen(DX_SCREEN_BACK);

		return true;
	}

	namespace Window {
		void SetTitle(const std::string& titleName) {
			DxLib::SetWindowTextDX(titleName.c_str());
		}

		void SetTitle(std::string_view titleName) {
			DxLib::SetWindowTextDX(titleName.data());
		}

		void SetWindowMode(bool enable) {
			DxLib::ChangeWindowMode(enable);
		}

		void SetAlwaysRun(bool enable) {
			DxLib::SetAlwaysRunFlag(enable);
		}

		void SetSize(int width, int height) {
			DxLib::SetWindowSize(width, height);
		}

		AyLib::Vector2 GetSizeF() {
			int w, h;

			DxLib::GetWindowSize(&w, &h);

			return AyLib::Vector2(static_cast<float>(w), static_cast<float>(h));
		}

		std::pair<int, int> GetSize() {
			int w, h;

			DxLib::GetWindowSize(&w, &h);

			return { w, h };
		}
	}

	namespace Screen {
		void SetResolution(int width, int height, int colorBit) {
			DxLib::SetGraphMode(width, height, colorBit);
		}

		void SetBgColor(const AyLib::Color& color) {
			DxLib::SetBackgroundColor(color.r, color.g, color.b, color.a);
		}
	}

	namespace System {
		void EnableLog(bool enable) {
			DxLib::SetOutApplicationLogValidFlag(enable);
		}
	}
}
