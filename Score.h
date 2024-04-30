#pragma once
#include "Engine/GameObject.h"
#include"Engine/Text.h"

class Score :
    public GameObject
{
	int playScore;
	Text* pText;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Score(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	void SetScore(int _score);
	int GetScore();
};

