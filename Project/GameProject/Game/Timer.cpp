#include "Timer.h"
#include"Task/Task.h"
Timer::Timer(const CVector2D& pos) :Task(eType_Timer, (int)TaskPrio::Timer)
{
    m_pos = pos;
	m_img.Load("Image/Timer.png");
}

void Timer::Draw()
{
    int score = 60;
    while (score != 0) {
        score--;
        if(score == 0) {
            score = 60;
            break;
        }
    }
   
    for (int i = 0; i < 2; i++, score /= 10) {
        int s = score % 10;
        m_img.SetRect(500 * s, 0, 500 * s + 500, 500);
        m_img.SetSize(100, 100);
        m_img.SetPos(930 - 60 * i, 150);
        m_img.Draw();
    }
}