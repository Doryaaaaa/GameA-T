#pragma once
#include "../Task/Task.h"

class Timer : public Task {
public:
    CImage m_img;
    CVector2D m_pos;
    int score;
public:
    Timer(const CVector2D& pos);
    void Update();
    void Draw();
};
