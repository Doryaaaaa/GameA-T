#include"Explanation.h"
#include"Task/Task.h"
#include"Game/Game.h"

Explanation::Explanation() :Task(eType_Explanation, (int)TaskPrio::Explanation),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
    m_img = COPY_RESOURCE("Explanation", CImage);
}
Explanation::~Explanation()
{
    //全てのオブジェクトを破棄
    IsKill();
    //ゲームシーンへ
    new Game();
}
void Explanation::Update()
{
    //ボタンAでタイトル破棄
    if (PUSH(CInput::eButton1)) {
        Kill();
    }
}

void Explanation::Draw()
{
    m_img.Draw();
}