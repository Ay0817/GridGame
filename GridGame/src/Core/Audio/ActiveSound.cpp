#include <DxLib.h>

#include <Core/Audio/ActiveSound.hpp>

namespace Core::Audio
{
	ActiveSound::ActiveSound(int handle)
		: _handle(handle)
	{}

	void ActiveSound::Stop() const {
		StopSoundMem(_handle);
	}

	bool ActiveSound::IsPlaying() const {
		return CheckSoundMem(_handle) == 1;
	}

	int ActiveSound::GetHandle() const {
		return _handle;
	}
}
