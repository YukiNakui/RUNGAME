#include "Load.h"
#include"Enemy.h"
#include"Engine/Model.h"

Load::Load(GameObject* parent)
	:GameObject(parent,"Load"),hModel_(-1)
{
}

void Load::Initialize()
{
	hModel_ = Model::Load("Model\\Load.fbx");
	assert(hModel_ >= 0);
	transform_.scale_ = XMFLOAT3(2.0f, 1.0f, 2.0f);
	Instantiate<Enemy>(this);
}

void Load::Update()
{
	transform_.position_.z -= 0.1f;
	if (transform_.position_.z <= -10)
	{
		KillMe();
	}
}

void Load::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Load::Release()
{
}
