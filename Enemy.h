#pragma once
#include "Engine/GameObject.h"
//#include"Score.h"

class Enemy :
    public GameObject
{
	int hModel_;
	float moveSpeed_;
	int score;
	//Score* pScore;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Enemy(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

