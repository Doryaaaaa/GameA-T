#pragma once
#include "../Task/Task.h"

class Timer : public Task {
public:
    CImage m_img;
public:
    Timer();
    void Draw();
};
