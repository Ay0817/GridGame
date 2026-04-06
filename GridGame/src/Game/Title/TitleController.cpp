#include <Game/Title/TitleController.hpp>
#include <Game/Scenes/PlayScene.hpp>
#include <Core/Input.hpp>
#include <Core/SceneAPI.hpp>

namespace Game
{
	void TitleController::Update() {
		if (Input::GetMouseButtonUp(MouseButtons::Right)) {
			SceneAPI::ChangeWithTransition<PlayScene>("Play");
		}
	}
}
