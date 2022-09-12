#include "Panel.h"

Panel::Panel()
{
    background = new Sprite("Resources/panel.png");
    numbers = new TileSet("Resources/numbers.png", 24, 32, 5, 10);
    anim = new Animation[9]{
        Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false),
        Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false),
        Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false), Animation(numbers, 0.0f, false),
    };
}

Panel::~Panel()
{
    delete[] anim;
    delete numbers;
    delete background;
}

void Panel::Update()
{
    time += gameTime;
}

void Panel::Draw()
{
    background->Draw(window->Width() / 2.0f, 40.0f, 0.9f);
    for (int i = 0; i < scoreTxt.length(); ++i)
        anim[i].Draw(scoreTxt.at(i) - '0', 36.0f + (24.0f * i), 58.0f, Layer::LOWER);
}

void Panel::AddScore(uint s)
{
    score += s;
    scoreTxt = (stringstream() << setw(9) << setfill('0') << to_string(score)).str();
}
