#include"GameClear.h"
#include"Title.h"
#include"Game/Timer.h"
#include"Task/Task.h"
#include"Game/Game.h"

GameClear::GameClear() :Task(eType_GameClear, (int)TaskPrio::GameClear),
m_GameClear_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
    m_img = COPY_RESOURCE("GameClear", CImage);

}
GameClear::~GameClear()
{
    IsKill();
    //�^�C�g���V�[����
    new Title();
}
void  GameClear::Update()
{
    //�{�^��Z�Ŕj��
    if (PUSH(CInput::eButton1)) {
        Kill();
    }
}

void  GameClear::Draw()
{
    m_img.Draw();
    m_GameClear_text.Draw(690, 650,1,0,0,"�N���A�^�C�� %d�b", Timer::Cscore);
}



//�Q�[���I�[�o�[
GameOver::GameOver() :Task(eType_GameOver, (int)TaskPrio::GameOver),
m_GameClear_text("C:\\Windows\\Fonts\\msgothic.ttc", 64)
{
    m_img = COPY_RESOURCE("GameOver", CImage);
}
GameOver::~GameOver()
{
    //�S�ẴI�u�W�F�N�g��j��
    IsKill();
    //�^�C�g���V�[����
    new Title();
}
void  GameOver::Update()
{
    //�{�^��Z�Ń^�C�g���j��
    if (PUSH(CInput::eButton1)) {
        Kill();
    }
}

void  GameOver::Draw()
{
    m_img.Draw();
}
