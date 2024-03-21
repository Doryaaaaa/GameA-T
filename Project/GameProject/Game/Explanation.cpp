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
    //�S�ẴI�u�W�F�N�g��j��
    IsKill();
    //�Q�[���V�[����
    new Game();
}
void Explanation::Update()
{
    //�{�^��A�Ń^�C�g���j��
    if (PUSH(CInput::eButton1)) {
        Kill();
    }
}

void Explanation::Draw()
{
    m_img.Draw();
}