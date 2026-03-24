#pragma once

#include <string_view>

#include "Asset.hpp"

/// @brief 再生時に必要なサウンド情報を持つ
class SoundData final : public Asset {
public:
	/// @brief コンストラクタ
	/// @param name サウンド名
	/// @param path ファイルパス
	SoundData(std::string_view name, std::string_view path);

	/// @brief デストラクタ
	virtual ~SoundData();

	/// @brief 解放
	virtual void Release() override;
};
