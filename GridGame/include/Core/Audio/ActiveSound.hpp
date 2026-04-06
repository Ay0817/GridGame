#pragma once

namespace Core::Audio 
{
	/// @brief 再生されるサウンド
	class ActiveSound {
	private:
		int _handle; // ハンドル
	public:
		/// @brief コンストラクタ
		/// @param handle ハンドル
		ActiveSound(int handle);

		/// @brief 再生を停止
		void Stop() const;

		/// @brief 再生中か？
		/// @return 再生状態
		[[nodiscard]]
		bool IsPlaying() const;

		/// @brief ハンドルを取得
		/// @return ハンドル
		[[nodiscard]]
		int GetHandle() const;
	};
}
