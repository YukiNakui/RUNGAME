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

	//‰Šú‰»
	void Initialize() override;

	//XV
	void Update() override;

	//•`‰æ
	void Draw() override;

	//ŠJ•ú
	void Release() override;

	int GetState();
};

