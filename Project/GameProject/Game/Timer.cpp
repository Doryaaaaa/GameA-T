#include "Timer.h"
#include"Task/Task.h"
#include"Task/TaskManager.h"
#include "Game/GameClear.h"
Timer::Timer(const CVector2D& pos) :Task(eType_Timer, (int)TaskPrio::Timer)
{
    m_pos = pos;
	m_img.Load("Image/Timer.png");
    score = 60*60;
}
void Timer::Draw()
{
    int ti = score / 60;
    score--;
    for (int i = 0; i < 2; i++, ti /= 10) {
        int s = ti % 10;
        m_img.SetRect(500 * s, 0, 500 * s + 500, 500);
        m_img.SetSize(100, 100);
        m_img.SetPos(960 - 60 * i, 150);
        m_img.Draw();
        if (score<0) {
            TaskManager::KillAll();
            (new GameOver());
        }
    }
}