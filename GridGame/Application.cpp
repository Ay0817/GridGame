#include <DxLib.h>

#include "Application.hpp"
#include "SceneManager.hpp"
#include "InputSystem.hpp"
#include "Input.hpp"
#include "SampleScene.hpp"

Application::Application()
    : _running(false)
{}

bool Application::Init() {
    SetAlwaysRunFlag(true);
    ChangeWindowMode(true);
    SetWindowTextDX("Lights Out");
    SetGraphMode(800, 600, 32);

    if (DxLib_Init() == -1) {
        return false;
    }

    SetDrawScreen(DX_SCREEN_BACK);

    _running = true;

    // 初期シーン
    SceneManager::Init<SampleScene>("Sample");

    return true;
}

void Application::Update() {
    if (ProcessMessage() == -1) {
        _running = false;
    }

    // ESC を押すと終了
    if (AyLib::Input::GetKeyDown(AyLib::Keys::ESC)) {
        _running = false;
    }

    // 更新
    AyLib::InputSystem::Update();
    SceneManager::Update();
}

void Application::Draw() {
    ClearDrawScreen();

    // 描画
    SceneManager::Draw();

    ScreenFlip();
}

void Application::Finalize() {
    AyLib::InputSystem::End();
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
