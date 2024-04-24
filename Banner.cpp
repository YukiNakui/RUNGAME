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
	switch (state_)
	{
	case Ready:
		cdTimer_ += 1.0f / 60.0f;
		if (cdTimer_ >= 1.5f)
		{
			state_ = Go;
			cdTimer_ = 0.0f;
		}
		break;
	case Go:
		cdTimer_ += 1.0f / 60.0f;
		if (cdTimer_ >= 1.5f)
		{
			state_ = Play;
			cdTimer_ = 0.0f;
		}
		break;
	case Play:
		break;
	default:
		break;
	}
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

int Banner::GetState()
{
    return state_;
}
