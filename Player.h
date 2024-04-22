#pragma once
#include "Engine/GameObject.h"

const float GRAVITY = 4.0f / 60.0f;
const float JUMP_HEIGHT = 3.0f;

class Player :
    public GameObject
{
	int hModel_;
	bool deadNow_;
	float jumpSpeed_;
	bool jumpNow;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Player(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	//�����ɓ�������
	//�����FpTarget ������������
	void OnCollision(GameObject* pTarget) override;

	bool GetDeadNow();
};

