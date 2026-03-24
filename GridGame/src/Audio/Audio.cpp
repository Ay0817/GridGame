#include <DxLib.h>

#include "../../include/Audio.hpp"

Audio::Audio(int volume)
	: Component()
	, _volume(volume)
{}

void Audio::SetVolume(int volume) {
	_volume = volume;
}

int Audio::GetVolume() const {
	return _volume;
}

ActiveSound Audio::Play(const std::shared_ptr<SoundData>& soundData, bool loop) {
	auto handle = DuplicateSoundMem(soundData->GetHandle());

	ChangeVolumeSoundMem(_volume, handle);

	auto type = loop ? DX_PLAYTYPE_LOOP : DX_PLAYTYPE_BACK;

	PlaySoundMem(handle, type);

	_sounds.emplace_back(handle);

	return _sounds.back();
}

void Audio::Stop() {
	for (auto& sound : _sounds) {
		sound.Stop();
	}

	_sounds.clear();
}

void Audio::Update() {
	std::erase_if(_sounds, [](const ActiveSound& v) {
		return !v.IsPlaying();
		});
}
