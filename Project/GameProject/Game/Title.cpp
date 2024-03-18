#include"Title.h"
#include"Task/Task.h"
#include"Game/Game.h"

Title::Title() :Task(eType_Title, (int)TaskPrio::Title),
m_title_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
    m_img = COPY_RESOURCE("Title", CImage);

}
Title::~Title()
{
    //�S�ẴI�u�W�F�N�g��j��
    IsKill();
    //�Q�[���V�[����
    new Game();
}
void Title::Update()
{
    //�{�^��A�Ń^�C�g���j��
    if (PUSH(CInput::eButton1)) {
        Kill();
    }
}

void Title::Draw()
{
    m_img.Draw();
}
