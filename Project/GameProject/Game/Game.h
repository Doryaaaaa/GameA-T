#pragma once
#include "../Task/Task.h"

class Timer;

class Game : public Task {

public:
    Game();
    ~Game();
    void Update();
    int cnt = 0;
};