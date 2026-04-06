#pragma once

#include <string>

namespace Core::Resource
{
	/// @brief アセットの基底クラス
	class Asset {
	protected:
		int _handle;
		std::string _name;
	public:
		Asset(const std::string& name);

		/// @brief デフォルトデストラクタ
		virtual ~Asset() = default;

		/// @brief 解放
		virtual void Release() = 0;

		/// @brief アセットのハンドルを取得
		/// @return アセットのハンドルを
		[[nodiscard]]
		int GetHandle() const;

		/// @brief アセット名を取得
		/// @return アセット名
		[[nodiscard]]
		std::string GetName();
	};
}
