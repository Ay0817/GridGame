#include <Windows.h>

#include "Application.hpp"

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
    Application app;

    return app.Run();
}
