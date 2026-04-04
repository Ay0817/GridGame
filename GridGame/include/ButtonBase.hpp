#pragma once

#include "Component.hpp"
#include "Action.hpp"
#include "RectTransform.hpp"

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
	Action<> OnClickCallBack;
	Action<bool> OnPressedCallBack;
	Action<> OnLongTappedCallback;
public:
	virtual void Begin() override;
	virtual void End() override;
	void SetEnable(bool state);
	bool IsEnabled() const;
	bool IsDisabled() const;
};
