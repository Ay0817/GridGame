#pragma once

#include "ButtonBase.hpp"
#include "Vector2.hpp"
#include "Audio.hpp"
#include "SpriteRenderer.hpp"

class GeneralButton : public ButtonBase {
protected:
	Vector2 _scale;
	float _target;
	float _targetScale;
	float _speed;
	bool _hasImage;

	AudioPlay _buttonSE;
	SpriteRenderer* _spriteRenderer;
	Transform* _transform;
protected:
	virtual void OnClicked() override;
	virtual void OnPressed(bool isPressed) override;
public:
	/// @brief コンストラクタ
	GeneralButton(std::shared_ptr<SoundData> soundData = nullptr, float targetScale = 0.7f, float scaleDuration = 0.2f);

	/// @brief 初期化処理
	virtual void Begin() override;

	/// @brief 更新処理
	virtual void Update() override;

	/// @brief 描画処理
	virtual void Draw() const override;
};
