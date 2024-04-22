#pragma once
#include "Engine/GameObject.h"
#include"Player.h"

class PlayScene :
    public GameObject
{
	int hImage_;
	double cdTimer_;
	double timerRate;
	int randW;
	int randX;
	Player* pPlayer;
	float deathTimer_;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	PlayScene(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;
};

