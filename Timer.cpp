#include "Timer.h"

Timer::Timer(GameObject* parent)
	:GameObject(parent,"Timer")
{
}

void Timer::Initialize()
{
	SetTimer(60.0);
	isTimerRun_ = true;
}

void Timer::Update()
{
	if(isTimerRun_)
	cdTimer_ = cdTimer_ - 1.0;
}

void Timer::Draw()
{
}

void Timer::Release()
{
}

void Timer::SetTimer(double _timer)
{
	TIMER_INIT_TIME = _timer;
	cdTimer_ = TIMER_INIT_TIME;
}

void Timer::ResetTimer()
{
	cdTimer_ = TIMER_INIT_TIME;
	StartTimer();
}

bool Timer::IsTimeOver()
{
	return (cdTimer_ < 0);
}

void Timer::StartTimer()
{
	isTimerRun_ = true;
}

void Timer::StopTimer()
{
	isTimerRun_ = false;
}
