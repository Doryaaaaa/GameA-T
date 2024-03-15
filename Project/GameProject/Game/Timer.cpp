#include "Timer.h"
#include"Task/Task.h"
Timer::Timer(const CVector2D& pos) :Task(eType_Timer, (int)TaskPrio::Timer)
{
    m_pos = pos;
	m_img.Load("Image/Timer.png");
    score = 60*60;
}
void Timer::Update() {
    int ti = score / 60;
        score--;
}