#pragma once
#include "Engine/GameObject.h"
#include"Engine/Text.h"

class Score :
    public GameObject
{
	int playScore;
	Text* pText;
public:
	//�R���X�g���N�^
	//�����Fparent  �e�I�u�W�F�N�g�iSceneManager�j
	Score(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	void SetScore(int _score);
	int GetScore();
};
