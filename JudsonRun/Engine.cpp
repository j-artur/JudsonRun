#include "Engine.h"
#include <windows.h>
#include <sstream>
using std::stringstream;

Game     * Engine::game      = nullptr;
Window   * Engine::window    = nullptr;
Graphics * Engine::graphics  = nullptr;
Renderer * Engine::renderer  = nullptr;
float      Engine::frameTime = 0.0f;
bool       Engine::paused    = false;
Timer      Engine::timer;

Engine::Engine()
{
    window     = new Window();
    graphics   = new Graphics();
    renderer   = new Renderer();
}

Engine::~Engine()
{
    delete game;
    delete renderer;
    delete graphics;
    delete window;
}

int Engine::Start(Game* level)
{
    game = level;

    window->Create();

    graphics->Initialize(window);

    renderer->Initialize(window, graphics);

    timeBeginPeriod(1);

    int exitCode = Loop();

    timeEndPeriod(1);

    return exitCode;
}

void Engine::Pause()
{
    paused = true;
    timer.Stop();
}

void Engine::Resume()
{
    paused = false;
    timer.Start();
}

int Engine::Loop()
{
    timer.Start();

    game->Init();

    MSG  msg = { 0 };

    bool pauseKeyCtrl = true;

    do
    {
        if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            if (pauseKeyCtrl)
            {
                if (window->KeyDown(VK_PAUSE))
                {
                    paused = !paused;
                    pauseKeyCtrl = false;

                    if (paused)
                        timer.Stop();
                    else
                        timer.Start();
                }
            }
            else
            {
                if (window->KeyUp(VK_PAUSE))
                    pauseKeyCtrl = true;
            }

            if (!paused)
            {
                frameTime = FrameTime();

                game->Update();

                graphics->Clear();

                game->Draw();

                renderer->Render();

                graphics->Present();
            }
            else
            {
                game->OnPause();
            }
        }

    } while (msg.message != WM_QUIT);

    game->Finalize();

    return int(msg.wParam);
}

float Engine::FrameTime()
{
#ifdef _DEBUG
    static float totalTime = 0.0f;
    static uint  frameCount = 0;
#endif
    frameTime = timer.Reset();

#ifdef _DEBUG
    totalTime += frameTime;

    frameCount++;

    if (totalTime >= 1.0f)
    {
        stringstream text;
        text << std::fixed;
        text.precision(3);

        text << window->Title().c_str() << "    "
            << "FPS: " << frameCount << "    "
            << "Frame Time: " << frameTime * 1000 << " (ms)";

        SetWindowText(window->Id(), text.str().c_str());

        frameCount = 0;
        totalTime -= 1.0f;
    }
#endif

    return frameTime;
}
