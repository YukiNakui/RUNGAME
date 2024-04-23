#include "TitleScene.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"
#include"Engine/Input.h"

TitleScene::TitleScene(GameObject* parent)
	:GameObject(parent,"TitleScene"),hImage_(-1),pText_(nullptr)
{
}

void TitleScene::Initialize()
{
	hImage_ = Image::Load("Title.png");
	assert(hImage_ >= 0);
	transform_.position_.y = 0.03f;
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
	Image::SetTransform(hImage_, transform_);
	Image::Draw(hImage_);
	pText_->Draw(500, 600, "Press to SPACE");
}

void TitleScene::Release()
{
}
