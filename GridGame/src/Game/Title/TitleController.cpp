#include "../../../include/TitleController.hpp"
#include "../../../include/Input.hpp"
#include "../../../include/PlayScene.hpp"
#include "../../../include/SceneAPI.hpp"

void TitleController::Update() {
	if (Input::GetMouseButtonUp(MouseButtons::Right)) {
		SceneAPI::ChangeWithTransition<PlayScene>("Play");
	}
}
