#include "Banner.h"
#include"Engine/Image.h"
#include"Engine/SceneManager.h"

Banner::Banner(GameObject* parent)
	:GameObject(parent,"Banner"),pText(nullptr)
{
}

void Banner::Initialize()
{
	pText = new Text;
	pText->Initialize();
	hReadyImage_ = Image::Load("READY.png");
	assert(hReadyImage_ >= 0);
	hGoImage_ = Image::Load("GO.png");
	assert(hGoImage_ >= 0);
	cdTimer_ = 0.0f;
	state_ = State::Ready;
	scaleRate = 1.0f;
	playScore = 0;
	readyTrans.position_ = { 0,0,0 };
	goTrans.position_ = { 0,0,0 };
}

void Banner::Update()
{
	readyTrans.scale_ = { scaleRate,scaleRate,scaleRate };
	goTrans.scale_ = { scaleRate,scaleRate,scaleRate };
}

void Banner::Draw()
{
	if (state_ == Ready)
	{
		Image::SetTransform(hReadyImage_, readyTrans);
		Image::Draw(hReadyImage_);
	}
	else if (state_ == Go)
	{
		Image::SetTransform(hGoImage_, goTrans);
		Image::Draw(hGoImage_);
	}
}

void Banner::Release()
{
}

void Banner::SetState(State _state)
{
	state_ = _state;
}

int Banner::GetState()
{
    return state_;
}

void Banner::SetScaleRate(float _scaleRate)
{
	scaleRate = _scaleRate;
}

float Banner::GetScaleRate()
{
	return scaleRate;
}
