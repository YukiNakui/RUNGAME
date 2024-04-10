#pragma once
#include "Engine/GameObject.h"

class Timer :
    public GameObject
{
	double TIMER_INIT_TIME;
	double timer_;
public:
	//コンストラクタ
	//引数：parent  親オブジェクト（SceneManager）
	Timer(GameObject* parent);

	//初期化
	void Initialize() override;

	//更新
	void Update() override;

	//描画
	void Draw() override;

	//開放
	void Release() override;

	double cdTimer_;
	bool isTimerRun_;
	void SetTimer(double _timer);
	void ResetTimer();
	bool IsTimeOver();
	void StartTimer();
	void StopTimer();
};

