#pragma once
#include "../Task/Task.h"

class Explanation : public Task {
    //�摜�I�u�W�F�N�g
    CImage m_img;
    //�����\���I�u�W�F�N�g
    CFont m_title_text;
public:
    Explanation();
    ~Explanation();
    void Update();
    void Draw();
};