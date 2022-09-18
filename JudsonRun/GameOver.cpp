#include "GameOver.h"

void GameOver::Init()
{
    bg = new Sprite("Resources/GameOver.png");
}

void GameOver::Finalize()
{
    delete bg;
}

void GameOver::Update()
{
    if (window->KeyDown(VK_RETURN))
        return Engine::Next<JudsonRun>();
}

void GameOver::Draw()
{
    bg->Draw(window->CenterX(), window->CenterY(), Layer::BACK);
}
