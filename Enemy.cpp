#include "Enemy.h"
#include"Engine/Model.h"
#include"Engine/SphereCollider.h"

Enemy::Enemy(GameObject* parent)
	:GameObject(parent,"Enemy")
{
}

void Enemy::Initialize()
{
	hModel_ = Model::Load("Model\\Enemy.fbx");
	assert(hModel_ >= 0);
	//transform_.scale_ = XMFLOAT3(0.5f, 0.5f, 0.5f);
	transform_.position_.z = 20.0f;
	transform_.rotate_.y = 180.0f;
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.5f, 0), 0.5f);
	AddCollider(collision);
}

void Enemy::Update()
{
	transform_.position_.z -= 0.1f;
	if (transform_.position_.z <= -5.0f) 
	{
		KillMe();
	}
}

void Enemy::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Enemy::Release()
{
}
