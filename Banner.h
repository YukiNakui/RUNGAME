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

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	int GetState();
};

