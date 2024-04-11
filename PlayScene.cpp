#include "PlayScene.h"
#include"Load.h"
#include"Enemy.h"
#include"Player.h"
#include"Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	cdTimer_ = 60.0;
	timerRate = 0.5;
	randW = 0;
	randX = 0;

	Instantiate<Load>(this);
	Instantiate<Player>(this);

	Camera::SetPosition(XMFLOAT3(0, 3, -8));
	Camera::SetTarget(XMFLOAT3(0, 0, 5));
}

void PlayScene::Update()
{
	cdTimer_ -= timerRate;
	if (cdTimer_ <= 0)
	{
		for (int i = 0; i < 2; i++)
		{
			while (randX == randW)
			{
				randX = rand() % 3;
				if (randX == 2)
					randX = -1;
			}
			Enemy* pEnemy = Instantiate<Enemy>(this);
			pEnemy->SetPosition(randX * 2.5f, 0, 20.0f);
			randW = randX;
		}
		cdTimer_ = 60.0;
		if(timerRate <= 2.0)
		timerRate += 0.02;
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
