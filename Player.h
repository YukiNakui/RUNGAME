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
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Player(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	//何かに当たった
	//引数：pTarget 当たった相手
	void OnCollision(GameObject* pTarget) override;

	bool GetDeadNow();
};

