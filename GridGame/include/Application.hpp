#pragma once

/// @brief アプリケーションの基幹クラス
class Application final {
private:
	bool _running; // 実行中か？
private:
	/// @brief 初期化処理
	/// @return 成功したら true, 失敗したら false を返す 
	bool Init();

	/// @brief 更新処理
	void Update();

	/// @brief 描画処理
	void Draw();

	/// @brief 終了時処理
	void Finalize();
public:
	/// @brief コンストラクタコンストラクタ
	Application();

	/// @brief 実行
	/// @return 成功したら 0, 失敗したら -1 を返す
	int Run();
};
