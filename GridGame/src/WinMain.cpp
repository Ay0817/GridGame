#include <Windows.h>

#include <Core/Application.hpp>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Core::Application app;

    return app.Run();
}
