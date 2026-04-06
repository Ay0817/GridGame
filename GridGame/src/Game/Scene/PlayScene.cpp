#include <Game/Scenes/PlayScene.hpp>
#include <Game/Grid/GridData.hpp>
#include <Game/Grid/GridRenderer.hpp>
#include <Game/LightsOut/LightsOut.hpp>
#include <Game/LightsOut/LightsOutInput.hpp>
#include <Game/LightsOut/LightsOutPlayTimer.hpp>
#include <Core/Core.hpp>
#include <AyLib/AyLib.hpp>

namespace Game
{
	PlayScene::PlayScene(const std::string& name)
		: Scene(name)
		, _gridConfig{ 100, Window::GetSize().first / 2, Window::GetSize().second / 2 }
	{}

	void PlayScene::Begin() {
		auto lightsOut = AddObject<GameObject>("LightsOut", Transform({ 10.f, 15.f }));
		auto font = Resource::AssetResolver::Load<Resource::Font>("CascadiaCode", "Resources/Fonts/CascadiaCode.ttf", Resource::FontInfo{ 32, 4, Resource::FontType::ANTI_ALIASING });

		lightsOut->AddComponent<GridData>();
		lightsOut->AddComponent<LightsOut>();
		lightsOut->AddComponent<LightsOutPlayTimer>();
		lightsOut->AddComponent<LightsOutInput>(_gridConfig);
		lightsOut->AddComponent<GridRenderer>(_gridConfig);
		lightsOut->AddComponent<Audio::SoundPlayer>();
		lightsOut->AddComponent<UI::Text>(UI::TextInfo{ "", font, UI::TextAlign{}, Palette::Vspo::Ema });

		Scene::Begin();
	}
}
