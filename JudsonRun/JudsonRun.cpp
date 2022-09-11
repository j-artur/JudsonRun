
#include "JudsonRun.h"
#include "Cpp.h"
#include "CppGenerator.h"
#include "Engine.h"
#include "Judson.h"
#include "Mouse.h"
#include "Resources.h"

Scene *JudsonRun::scene = nullptr;

void JudsonRun::Init()
{
    scene = new Scene();

    bg = new Sprite("Resources/background.png");
    shadow = new Image("Resources/shadow.png");

    auto cppGenerator = new CppGenerator(shadow);
    scene->Add(cppGenerator, STATIC);

    auto mouse = new Mouse();
    scene->Add(mouse, MOVING);

    auto judson = new Judson(shadow);
    judson->MoveTo(window->CenterX(), window->CenterY());
    scene->Add(judson, MOVING);
}

void JudsonRun::Update()
{
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    scene->CollisionDetection();

    scene->Update();
}

void JudsonRun::Draw()
{
    bg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
    scene->Draw();
}

void JudsonRun::Finalize()
{
    delete scene;
}

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                     _In_ int nCmdShow)
{
    Engine *engine = new Engine();

    // engine->window->Mode(FULLSCREEN);
    engine->window->Mode(WINDOWED);
    engine->window->Size(1280, 720);
    engine->window->Color(127, 127, 127);
    engine->window->Title("Judson, Run!");
    engine->window->Icon(IDI_ICON);
    // engine->window->Cursor(IDC_CURSOR);
    // engine->graphics->VSync(true);

    int status = engine->Start(new JudsonRun());

    delete engine;
    return status;
}
