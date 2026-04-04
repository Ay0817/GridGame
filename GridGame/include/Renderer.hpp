#pragma once

#include "Component.hpp"

/// @brief 描画を担当するコンポーネントの基底
class Renderer : public Component {
protected:
	int _layer = 0; // 描画レイヤー
	int _order = 0; // 同一レイヤー内の描画順
public:
	/// @brief コンストラクタ
	/// @param layer 描画レイヤー
	/// @param order 同一レイヤー内の描画順
	Renderer(int layer, int order);

	/// @brief 描画レイヤーを取得
	/// @return 描画レイヤー
	int GetLayer() const;

	/// @brief 描画レイヤーを設定
	/// @param layer 描画レイヤー
	void SetLayer(int layer);

	/// @brief 同一レイヤー内の描画順を取得
	/// @return 同一レイヤー内の描画順
	int GetOrder() const;

	/// @brief 同一レイヤー内の描画順を設定
	/// @param order 同一レイヤー内の描画順
	void SetOrder(int order);
};
