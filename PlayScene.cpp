#include "PlayScene.h"
#include"Load.h"
#include"Player.h"
#include"Engine/Camera.h"

PlayScene::PlayScene(GameObject* parent)
	:GameObject(parent,"PlayScene")
{
}

void PlayScene::Initialize()
{

	Instantiate<Load>(this);
	Instantiate<Player>(this);
	Camera::SetPosition(XMFLOAT3(0, 5, -8));
	Camera::SetTarget(XMFLOAT3(0, 0, 5));
}

void PlayScene::Update()
{
}

void PlayScene::Draw()
{
}

void PlayScene::Release()
{
}
