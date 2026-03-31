#pragma once

#include "Component.hpp"
#include "Audio.hpp"
#include "Grid.hpp"
#include "LightsOutPlayTimer.hpp"

/// @brief @brief グリッドゲーム本体
class LightsOut final : public Component {
private:
	AudioPlay _clearSound;                    // クリア時のサウンド
	Grid* _grid = nullptr;                    // グリッド
	LightsOutPlayTimer* _playTimer = nullptr; // プレイ時間を計測

	bool _isCleared = false; // クリア済みか？
public:
	/// @brief 初期化処理
	virtual void Begin() override;

	/// @brief 更新処理
	virtual void Update() override;
};
