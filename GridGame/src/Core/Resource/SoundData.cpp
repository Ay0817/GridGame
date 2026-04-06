#include <DxLib.h>

#include <Core/Resource/SoundData.hpp>

namespace Core::Resource
{
	SoundData::SoundData(std::string_view name, std::string_view path)
		: Asset(std::string(name))
	{
		if (_handle == -1) {
			_handle = LoadSoundMem(path.data());
		}
	}

	SoundData::~SoundData() {
		Release();
	}

	void SoundData::Release() {
		if (_handle != -1) {
			DeleteSoundMem(_handle);
		}
	}
}
