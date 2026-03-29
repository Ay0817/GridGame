#include <DxLib.h>

#include "../../include/Application.hpp"
#include "../../include/SceneManager.hpp"
#include "../../include/InputSystem.hpp"
#include "../../include/Input.hpp"
#include "../../include/TimeImpl.hpp"
#include "../../include/SampleScene.hpp"
#include "../../include/Title.hpp"
#include "../../include/Palette.hpp"
#include "../../include/TransitionManager.hpp"

Application::Application()
    : _running(false)
{}

bool Application::Init() {
    SetOutApplicationLogValidFlag(false);
    SetAlwaysRunFlag(true);
    ChangeWindowMode(true);
    SetWindowTextDX("Lights Out");
    SetGraphMode(800, 600, 32);
	SetBackgroundColor(Palette::Basic::White.r, Palette::Basic::White.g, Palette::Basic::White.b);

    if (DxLib_Init() == -1) {
        return false;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    _running = true;

    TimeImpl::Init();

    // 初期シーン
    //SceneManager::Init<SampleScene>("Sample");
    SceneManager::Init<Title>("Title");

    return true;
}

void Application::Update() {
    if (ProcessMessage() == -1) {
        _running = false;
    }

    // ESC を押すと終了
    if (Input::GetKeyDown(Keys::ESC)) {
        _running = false;
    }

    // 更新
    TimeImpl::Update();
    InputSystem::Update();
    TransitionManager::Update();
    SceneManager::Update();
}

void Application::Draw() {
    ClearDrawScreen();

    // 描画
    SceneManager::Draw();
    TransitionManager::Draw();

    ScreenFlip();
}

void Application::Finalize() {
    InputSystem::End();
    SceneManager::End();

    DxLib_End();
}

int Application::Run() {
    if (!Init()) {
        return -1;
    }

    while (_running) {
        Update();
        Draw();
    }

    Finalize();

    return 0;
}
