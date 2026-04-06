#pragma once

#include "Core/Component.hpp"
#include "Core/RectTransform.hpp"
#include "AyLib/Action.hpp"

namespace Core::UI
{
	class GestureDetector final : public Component {
	private:
		const float LONG_TAP_TIME = 0.5f;
		const float CLICK_INTERVAL = 0.5f;

		float _pressTime;
		float _lastPressTime;
		bool _isPressed = false;
		bool _isLongTapTriggered = false;

		RectTransform* _rectTransform;
	private:
		bool IsPointerOver();
	public:
		AyLib::Action<> OnClickCallBack;
		AyLib::Action<bool> OnPressedCallBack;
		AyLib::Action<> OnLongTappedCallBack;
	public:
		/// @brief コンストラクタ
		GestureDetector();

		/// @brief 初期化処理
		virtual void Begin() override;

		/// @brief 更新処理
		virtual void Update() override;
	};
}
