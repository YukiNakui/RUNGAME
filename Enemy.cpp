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
	moveSpeed_ = 0;
	score = 0;
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.5f, 0), 0.5f);
	AddCollider(collision);
}

void Enemy::Update()
{
	moveSpeed_ += 0.01;
	float r = sinf(moveSpeed_ * (3.14 / 2.0f));
	transform_.position_.z -= r;
	if (transform_.position_.z <= -5.0f) 
	{
		score += 1;
//		pScore->SetScore(score);
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
