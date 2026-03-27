#pragma once

#include "Component.hpp"

/// @brief タイトルシーン全体の制御
class TitleController final : public Component {
public:
	/// @brief 更新処理
	virtual void Update() override;
};
