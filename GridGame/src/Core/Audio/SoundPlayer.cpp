#include <DxLib.h>

#include <Core/Audio/SoundPlayer.hpp>

namespace Core::Audio
{
	SoundPlayer::SoundPlayer(int volume)
		: Component()
		, _volume(volume)
	{}

	void SoundPlayer::SetVolume(int volume) {
		_volume = volume;
	}

	int SoundPlayer::GetVolume() const {
		return _volume;
	}

	ActiveSound SoundPlayer::Play(const std::shared_ptr<Resource::SoundData>& soundData, bool loop) {
		auto handle = DuplicateSoundMem(soundData->GetHandle());

		ChangeVolumeSoundMem(_volume, handle);

		auto type = loop ? DX_PLAYTYPE_LOOP : DX_PLAYTYPE_BACK;

		PlaySoundMem(handle, type);

		_sounds.emplace_back(handle);

		return _sounds.back();
	}

	void SoundPlayer::Stop() {
		for (auto& sound : _sounds) {
			sound.Stop();
		}

		_sounds.clear();
	}

	void SoundPlayer::Update() {
		std::erase_if(_sounds, [](const ActiveSound& v) {
			return !v.IsPlaying();
			});
	}
}
