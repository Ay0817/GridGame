#pragma once

#include <string>
#include <memory>

#include "Core/Component.hpp"
#include "Core/Transform.hpp"
#include "AyLib/Color.hpp"
#include "../Resource/Font.hpp"


namespace Core::UI
{
	/// @brief 横方向
	enum class HorizontalAlign {
		None,
		Left,
		Mid,
		Right
	};

	/// @brief 縦方向
	enum class VerticalAlign {
		None,
		Top,
		Mid,
		Bot
	};

	/// @brief テキストの配置
	struct TextAlign {
		HorizontalAlign horizontal;
		VerticalAlign vertical;

		TextAlign(HorizontalAlign h = HorizontalAlign::Mid, VerticalAlign v = VerticalAlign::Mid)
			: horizontal(h), vertical(v) {
		}
	};

	/// @brief テキストを描画する際に必要な情報を持つ
	struct TextInfo {
		std::string text;
		std::shared_ptr<Resource::Font> font;
		TextAlign textAlign;
		AyLib::Color color;
	};

	/// @brief テキストを表示
	class Text final : public Component {
	private:
		TextInfo _textInfo; // テキスト情報
		Transform* _transformCached = nullptr; // Transform cache
	private:
		int GetAlignedX(int baseX, int textWidth) const;
		int GetAlignedY(int baseY, int textHeight) const;
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

		/// @brief テキストの色を設定
		/// @param color 色
		void SetColor(const AyLib::Color& color);

		/// @brief テキストの色を取得
		/// @return テキストの色
		[[nodiscard]]
		AyLib::Color GetColor() const;
	};
}
