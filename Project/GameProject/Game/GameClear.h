#pragma once
#include "../Task/Task.h"

class GameClear : public Task {
    //�摜�I�u�W�F�N�g
    CImage m_img;
    //�����\���I�u�W�F�N�g
    CFont m_GameClear_text;
public:
    GameClear();
    ~GameClear();
    void Update();
    void Draw();
};



class GameOver : public Task {
    //�摜�I�u�W�F�N�g
    CImage m_img;
    //�����\���I�u�W�F�N�g
    CFont m_GameClear_text;
public:
    GameOver();
    ~GameOver();
    void Update();
    void Draw();
};
