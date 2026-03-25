#pragma once

#include "Scene.hpp"
#include "Text.hpp"
#include "Font.hpp"

/// @brief タイトルシーン
class Title final : public Scene {
private:
	TextInfo _textInfo;
	FontInfo _fontInfo;
public:
	/// @brief コンストラクタ
	/// @param name シーン名
	Title(const std::string& name);

	/// @brief 初期化処理
	virtual void Begin() override;
};
