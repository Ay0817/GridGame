#pragma once

#include <string>

#include "Core/Scene.hpp"

namespace Game
{
	/// @brief タイトルシーン
	class Title final : public Core::Scene {
	public:
		/// @brief コンストラクタ
		/// @param name シーン名
		Title(const std::string& name);

		/// @brief 初期化処理
		virtual void Begin() override;
	};
}
