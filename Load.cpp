#include "Load.h"
#include"Enemy.h"
#include"Engine/Model.h"

Load::Load(GameObject* parent)
	:GameObject(parent,"Load"),hModel_(-1)
{
}

void Load::Initialize()
{
	hModel_ = Model::Load("Model\\Load2.fbx");
	assert(hModel_ >= 0);
	transform_.position_.z = 13.0f;
	transform_.scale_ = XMFLOAT3(2.0f, 1.0f, 2.5f);
	//Instantiate<Enemy>(this);
}

void Load::Update()
{
	/*transform_.position_.z -= 0.1f;
	if (transform_.position_.z <= -10)
	{
		KillMe();
	}*/
}

void Load::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Load::Release()
{
}
