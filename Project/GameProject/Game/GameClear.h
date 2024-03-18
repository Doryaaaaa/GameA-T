#pragma once
#include "../Task/Task.h"

class GameClear : public Task {
    //画像オブジェクト
    CImage m_img;
    //文字表示オブジェクト
    CFont m_GameClear_text;
public:
    GameClear();
    ~GameClear();
    void Update();
    void Draw();
};



class GameOver : public Task {
    //画像オブジェクト
    CImage m_img;
    //文字表示オブジェクト
    CFont m_GameClear_text;
public:
    GameOver();
    ~GameOver();
    void Update();
    void Draw();
};
