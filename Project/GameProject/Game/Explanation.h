#pragma once
#include "../Task/Task.h"

class Explanation : public Task {
    //画像オブジェクト
    CImage m_img;
    //文字表示オブジェクト
    CFont m_title_text;
public:
    Explanation();
    ~Explanation();
    void Update();
    void Draw();
};