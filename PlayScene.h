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
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	PlayScene(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;
};

