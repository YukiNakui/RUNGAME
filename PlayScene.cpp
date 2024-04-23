#include "PlayScene.h"
#include"Load.h"
#include"Enemy.h"
#include"Engine/Camera.h"
#include"Engine/SceneManager.h"
#include"Engine/Image.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{
	hImage_= Image::Load("comand.png");
	assert(hImage_ >= 0);
	cdTimer_ = 60.0;
	timerRate = 0.5;
	randW = 0;
	randX = 0;
	deathTimer_ = 0.0f;
	sinCamAngle_ = 0;
	sinImgAngle_ = 0;

	Instantiate<Load>(this);
	pPlayer = Instantiate<Player>(this);
	camPos_ = { 0, 3, -8 };
	Camera::SetPosition(camPos_);
	Camera::SetTarget(XMFLOAT3(0, 0, 5));
	imgTrans.position_ = { -0.8,0.5,0 };
	imgTrans.scale_ = { 0.15,0.15,0.15 };
}

void PlayScene::Update()
{
	if (pPlayer->GetDeadNow())
	{
		deathTimer_ += 1.0f / 60.0f;
		sinCamAngle_ += 20.0f;
		sinImgAngle_ += 40.0f;
		float sinCamValue = sinf(sinCamAngle_ * 3.14f / 180.0f);
		float sinImgValue = sinf(sinImgAngle_ * 3.14f / 180.0f);
		camPos_.x = sinCamValue * 2.0f;
		Camera::SetPosition(camPos_);
		Camera::SetTarget(XMFLOAT3(camPos_.x, 0, 5));
		imgTrans.position_.x = imgTrans.position_.x + (sinImgValue) / 15.0f;
		if (deathTimer_ >= 1.5f)
		{
			SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
			pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
		}
	}
	else
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
			if (timerRate <= 1.0)
				timerRate += 0.02;
		}
	}
}

void PlayScene::Draw()
{
	Image::SetTransform(hImage_, imgTrans);
	Image::Draw(hImage_);
}

void PlayScene::Release()
{
}
