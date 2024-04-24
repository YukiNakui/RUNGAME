#include "TitleScene.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"),hTitleImage_(-1),hPushImage_(-1), pText_(nullptr)
{
}

void TitleScene::Initialize()
{
	hTitleImage_ = Image::Load("Title.png");
	assert(hTitleImage_ >= 0);
	hPushImage_ = Image::Load("PLESS TO SPACE.png");
	assert(hPushImage_ >= 0);
	pText_ = new Text;
	pText_->Initialize();
}

void TitleScene::Update()
{
	if (Input::IsKeyDown(DIK_SPACE))
	{
		SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
		pSceneManager->ChangeScene(SCENE_ID_PLAY);
	}
}

void TitleScene::Draw()
{
	Transform titleTrans_;
	titleTrans_.position_ = { 0,0.03f,0 };
	Transform pushTrans_;
	pushTrans_.position_ = { 0,-0.5,0 };
	pushTrans_.scale_ = { 0.5,0.5,0.5 };
	Image::SetTransform(hTitleImage_, titleTrans_);
	Image::Draw(hTitleImage_);
	Image::SetTransform(hPushImage_, pushTrans_);
	Image::Draw(hPushImage_);
	//pText_->Draw(500, 600, "Press to SPACE");
}

void TitleScene::Release()
{
}
