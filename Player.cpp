#include "Player.h"
#include"Engine/Model.h"
#include"Engine/Input.h"
#include"Engine/SphereCollider.h"
#include"Engine/SceneManager.h"

Player::Player(GameObject* parent)
	:GameObject(parent,"Player")
{
}

void Player::Initialize()
{
	hModel_ = Model::Load("Model\\Player.fbx");
	assert(hModel_ >= 0);
	transform_.position_.z = -2.0f;
	transform_.position_.y = 0.0f;
	transform_.scale_ = XMFLOAT3(1.5f, 1.5f, 1.5f);
	jumpSpeed_ = 0.0f;
	jumpNow = false;
	deadNow_ = false;
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.5f, 0), 0.5f);
	AddCollider(collision);
}

void Player::Update()
{
	if (!jumpNow)
	{
		if ((Input::IsKeyDown(DIK_RIGHT) || Input::IsKeyDown(DIK_D)) && (transform_.position_.x < 2.5f))
		{
			transform_.position_.x += 2.5f;
		}
		else if ((Input::IsKeyDown(DIK_LEFT) || Input::IsKeyDown(DIK_A)) && (transform_.position_.x > -2.5f))
		{
			transform_.position_.x -= 2.5f;
		}
	}
	if (Input::IsKeyDown(DIK_SPACE) && !(transform_.position_.y > 0))
	{
		jumpNow = true;
		jumpSpeed_ = -sqrt(2 * GRAVITY * JUMP_HEIGHT);
	}

	jumpSpeed_ += GRAVITY;
	transform_.position_.y -= jumpSpeed_;

	if (transform_.position_.y <0)
	{
		jumpNow = false;
		transform_.position_.y = 0;
		jumpSpeed_ = 0.0f;
	}
}

void Player::Draw()
{
	Model::SetTransform(hModel_, transform_);
	Model::Draw(hModel_);
}

void Player::Release()
{
}

void Player::OnCollision(GameObject* pTarget)
{
	KillMe();
	deadNow_ = true;
}

bool Player::GetDeadNow()
{
	return deadNow_;
}
