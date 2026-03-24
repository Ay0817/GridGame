#pragma once

#include <memory>
#include <vector>

#include "Component.hpp"
#include "SoundData.hpp"
#include "ActiveSound.hpp"

/// @brief 音の再生、停止の制御を行う
class Audio : public Component {
private:
	int _volume; // 音量

	std::vector<ActiveSound> _sounds; // 再生しているサウンドのハンドル
public:
	/// @brief コンストラクタ
	/// @param volume 
	/// @param loop 
	Audio(int volume = 128);

	/// @brief 音量を変更する
	void SetVolume(int volume);

	/// @brief 音量を取得する
	/// @return 音量
	int GetVolume() const;

	/// @brief 再生を開始
	ActiveSound Play(const std::shared_ptr<SoundData>& soundData, bool loop = false);

	/// @brief 再生を停止
	void Stop();

	/// @brief 更新処理
	virtual void Update() override;
};

/// @brief サウンド再生用構造体
struct AudioPlay {
	Audio* audio = nullptr;                         // Audio へのポインタ
	std::shared_ptr<SoundData> soundData = nullptr; // SoundData へのポインタ
};
