#pragma once

#include "Core/Component.hpp"

namespace Game
{
	/// @brief タイトルシーン全体の制御
	class TitleController final : public Core::Component {
	public:
		/// @brief 更新処理
		virtual void Update() override;
	};
}
