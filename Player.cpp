#include "Player.h"
#include"Engine/Model.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player")
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.z = -2.0f;
	transform_.position_.y = 0.3f;
	transform_.scale_ = XMFLOAT3(1.5f, 1.5f, 1.5f);
}

void Player::Update()
{
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}
