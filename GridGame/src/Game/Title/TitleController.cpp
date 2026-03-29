#include "../../../include/TitleController.hpp"
#include "../../../include/Input.hpp"
#include "../../../include/SampleScene.hpp"
#include "../../../include/SceneAPI.hpp"

void TitleController::Update() {
	if (Input::GetMouseButtonUp(MouseButtons::Left)) {
		SceneAPI::ChangeWithTransition<SampleScene>("Sample");
	}
}
