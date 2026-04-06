#pragma once

#include "ButtonBase.hpp"
#include "AyLib/Vector2.hpp"
#include "Core/SpriteRenderer.hpp"
#include "Core/Audio/SoundPlayer.hpp"
#include "Core/Resource/SoundData.hpp"

namespace Core::UI
{
	class GeneralButton : public ButtonBase {
	protected:
		AyLib::Vector2 _scale;
		float _target;
		float _targetScale;
		float _speed;
		bool _hasImage;

		Audio::AudioPlay _buttonSE;
		SpriteRenderer* _spriteRenderer;
		Transform* _transform;
	protected:
		virtual void OnClicked() override;
		virtual void OnPressed(bool isPressed) override;
	public:
		/// @brief コンストラクタ
		GeneralButton(std::shared_ptr<Resource::SoundData> soundData = nullptr, float targetScale = 0.7f, float scaleDuration = 0.2f);

		/// @brief 初期化処理
		virtual void Begin() override;

		/// @brief 更新処理
		virtual void Update() override;

		/// @brief 描画処理
		virtual void Draw() const override;
	};
}
