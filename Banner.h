#pragma once
#include "Engine/GameObject.h"
class Banner :
    public GameObject
{
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


	enum State {
		Ready,
		Go,
		Play,
	};
	State state_;

	void SetState(State _state);
	int GetState();
};

