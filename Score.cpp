#include "Score.h"

Score::Score(GameObject* parent)
	:GameObject(parent,"Score"),pText(nullptr)
{
}

void Score::Initialize()
{
	pText = new Text;
	pText->Initialize();
	playScore = 0;
}

void Score::Update()
{
}

void Score::Draw()
{
	pText->Draw(30, 30, playScore);
}

void Score::Release()
{
}

void Score::SetScore(int _score)
{
	playScore = _score;
}

int Score::GetScore()
{
	return playScore;
}
