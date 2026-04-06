#include <DxLib.h>

#include <Core/Application.hpp>
#include <Core/Core.hpp>
#include <AyLib/AyLib.hpp>
#include <Game/Scenes/Title.hpp>

namespace Core
{
    Application::Application()
        : _running(false)
    {}

    bool Application::Init() {
        if (!DxLap::Init(DxLap::Config{}
            .SetTitle("Lights Out")
            .SetWindowMode(true)
            .SetAlwaysRun(true)
            .SetWindowSize(1280, 720)
            .EnableLog(false)
            .SetBackground(Palette::Basic::White)
        )) {
            return false;
        }
        _running = true;

        TimeImpl::Init();
        SceneManager::Init<Game::Title>("Title");

        return true;
    }

    void Application::Update() {
        if (ProcessMessage() == -1) {
            _running = false;
        }

        // ESC ÇâüÇ∑Ç∆èIóπ
        if (Input::GetKeyDown(Keys::ESC)) {
            _running = false;
        }

        // çXêV
        TimeImpl::Update();
        InputSystem::Update();
        TransitionManager::Update();
        SceneManager::Update();
    }

    void Application::Draw() {
        ClearDrawScreen();

        // ï`âÊ
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
}
