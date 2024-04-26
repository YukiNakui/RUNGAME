#include "Banner.h"
#include"Engine/Image.h"

Banner::Banner(GameObject* parent)
{
}

void Banner::Initialize()
{
	hReadyImage_ = Image::Load("READY.png");
	assert(hReadyImage_ >= 0);
	hGoImage_ = Image::Load("GO.png");
	assert(hGoImage_ >= 0);
	cdTimer_ = 0.0f;
	state_ = State::Ready;
	scaleRate = 1.0f;
	readyTrans.position_ = { 0,0,0 };
	readyTrans.scale_ = { scaleRate,scaleRate,scaleRate };
	goTrans.position_ = { 0,0,0 };
	goTrans.scale_ = { scaleRate,scaleRate,scaleRate };
}

void Banner::Update()
{
	/*if (state_ == Ready)
	{
		scaleRate -= 12.0f / 60.0f;
		if (scaleRate <= 1.0f)
		{
			scaleRate = 1.0f;
		}
	}
	if (state_ == Go)
	{
		scaleRate -= 12.0f / 60.0f;
		if (scaleRate <= 1.0f)
		{
			scaleRate = 1.0f;
		}
	}*/
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
