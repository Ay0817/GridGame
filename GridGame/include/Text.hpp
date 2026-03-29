#pragma once

#include <string>
#include <memory>

#include "Component.hpp"
#include "Transform.hpp"
#include "Font.hpp"
#include "Color.hpp"

/// @brief 
enum class TextAlign {
	Left,
	Center,
	Right
};

/// @brief テキストを描画する際に必要な情報を持つ
struct TextInfo {
	std::string text;
	std::shared_ptr<Font> font;
	TextAlign textAlign;
	Color color;
};

/// @brief テキストを表示
class Text final : public Component {
private:
	TextInfo _textInfo; // テキスト情報
	Transform* _transformCached = nullptr; // Transform cache
private:
	int GetAlignedX(int baseX, int textWidth) const;
public:
	/// @brief コンストラクタ
	/// @param textInfo テキスト情報
	Text(const TextInfo& textInfo);

	/// @brief 初期化処理
	virtual void Begin() override;

	/// @brief 描画処理
	virtual void Draw() const override;

	/// @brief テキストを設定
	/// @param text テキスト
	void SetText(const std::string& text);
};
