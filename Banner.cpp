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
}

void Banner::Update()
{
}

void Banner::Draw()
{
	Transform readyTrans;
	Transform goTrans;
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
