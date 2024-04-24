#pragma once
#include "Engine/GameObject.h"
class Banner :
    public GameObject
{
	enum State {
		Ready,
		Go,
		Play,
	};
	State state_;
	int hReadyImage_;
	int hGoImage_;
	double cdTimer_;
public:
	Banner(GameObject* parent);

	//������
	void Initialize() override;

	//�X�V
	void Update() override;

	//�`��
	void Draw() override;

	//�J��
	void Release() override;

	int GetState();
};

