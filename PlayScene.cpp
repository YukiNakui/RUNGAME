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
	Instantiate<Load>(this);
	
	/*int w = rand() % 3;
	for (int i = 0; i < 2; i++)
	{
		int randx = rand() % 3;
		while (randx == w)
			randx = rand() % 3;
		int w = randx;
		if (randx == 2)
			randx = -1;
		Enemy* pEnemy = Instantiate<Enemy>(this);
		pEnemy->SetPosition(randx * 2.5f, 0, 0);
	}*/
	Instantiate<Player>(this);
	Camera::SetPosition(XMFLOAT3(0, 3, -8));
	Camera::SetTarget(XMFLOAT3(0, 0, 5));
}

void PlayScene::Update()
{
	cdTimer_ -= 0.5;
	if (cdTimer_ <= 0)
	{
		for (int i = 0; i < 2; i++)
		{
			int randx = rand() % 3;
			if (randx == 2)
				randx = -1;
			Enemy* pEnemy = Instantiate<Enemy>(this);
			pEnemy->SetPosition(randx * 2.5f, 0, 20.0f);
		}
		cdTimer_ = 60.0;
	}
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
