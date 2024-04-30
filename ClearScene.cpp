#include "ClearScene.h"
#include"Engine/Image.h"
#include"Score.h"

ClearScene::ClearScene(GameObject* parent)
	:GameObject(parent,"ClearScene"),hImage_(-1)
{
}

void ClearScene::Initialize()
{
	hImage_ = Image::Load("GameOver.png");
	assert(hImage_ >= 0);
	Instantiate<Score>(this);
}

void ClearScene::Update()
{
}

void ClearScene::Draw()
{
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
}

void ClearScene::Release()
{
}
