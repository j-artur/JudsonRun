#include "Home.h"
#include "JudsonRun.h"

void Home::Init()
{
    bg2 = new Sprite("Resources/Home.png");
}

void Home::Finalize()
{
    delete bg2;
}

void Home::Update()
{
    if (window->KeyDown(VK_RETURN))
        return Engine::Next<JudsonRun>();
}

void Home::Draw()
{
    bg2->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}
