#include "../../../include/TitleController.hpp"
#include "../../../include/Input.hpp"
#include "../../../include/SampleScene.hpp"
#include "../../../include/SceneManager.hpp"

void TitleController::Update() {
	if (Input::GetMouseButtonUp(MouseButtons::Left)) {
		SceneManager::LoadScene(std::make_unique<SampleScene>("Sample"));
	}
}
