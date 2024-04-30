#pragma once
#include "Engine/GameObject.h"
#include"Player.h"
#include"Banner.h"
#include"Engine/Text.h"

class PlayScene :
    public GameObject
{
	int hImage_;
	int hReadyImage_;
	int hGoImage_;
	double cdTimer_;
	double timerRate;
	int randW;
	int randX;
	Player* pPlayer;
	Banner* pBanner;
	float deathTimer_;
	float sinCamAngle_;
	float sinImgAngle_;
	XMFLOAT3 camPos_;
	Transform imgTrans;
	float scaleRate;
	Text* pText;
	float correctCam;
	float correctImg;
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

