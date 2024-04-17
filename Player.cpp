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
	SphereCollider* collision = new SphereCollider(XMFLOAT3(0, 0.5f, 0), 0.5f);
	AddCollider(collision);
}

void Player::Update()
{
	if ((Input::IsKeyDown(DIK_RIGHT) || Input::IsKeyDown(DIK_D)) && (transform_.position_.x < 2.5f))
	{
		transform_.position_.x += 2.5f;
	}
	else if ((Input::IsKeyDown(DIK_LEFT) || Input::IsKeyDown(DIK_A)) && (transform_.position_.x > -2.5f))
	{
		transform_.position_.x -= 2.5f;
	}
	else if (Input::IsKeyDown(DIK_SPACE) && !(transform_.position_.y > 0))
	{
		
	}

	if (transform_.position_.y <= 0)
		transform_.position_.y = 0;
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
	SceneManager* pSceneManager = (SceneManager*)FindObject("SceneManager");
	pSceneManager->ChangeScene(SCENE_ID_GAMEOVER);
}
