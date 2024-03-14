#include "Timer.h"
#include"Task/Task.h"
Timer::Timer() :Task(eType_Timer, (int)TaskPrio::Timer)
{
	m_img.Load("Image/Timer.png");
}

void Timer::Draw()
{
    int score = 60;
    for (int i = 0; i < 2; i++, score /= 10) {
        int s = score % 10;
        m_img.SetRect(0 * s, 0, 500 * s + 500, 32);
        m_img.SetSize(500, 500);
        m_img.SetPos(800 - 500 * i, 100);
        m_img.Draw();
    }
}