#pragma once

#include "Core/Component.hpp"
#include "Core/RectTransform.hpp"
#include "AyLib/Action.hpp"

namespace Core::UI
{
	class ButtonBase : public Component {
	private:
		bool _isEnabled = false; // ボタンが有効か？
	private:
		void OnClickedHandler();
		void OnPressedHandler(bool isPressed);
		void OnLongTappedHandler();
	protected:
		RectTransform* _rectTransform;
	protected:
		virtual void OnClicked();
		virtual void OnPressed(bool isPressed);
		virtual void OnLongTapped();
	public:
		AyLib::Action<> OnClickCallBack;
		AyLib::Action<bool> OnPressedCallBack;
		AyLib::Action<> OnLongTappedCallback;
	public:
		virtual void Begin() override;
		virtual void End() override;
		void SetEnable(bool state);
		[[nodiscard]]
		bool IsEnabled() const;
		[[nodiscard]]
		bool IsDisabled() const;
	};
}
