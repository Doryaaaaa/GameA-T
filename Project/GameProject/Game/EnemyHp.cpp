#include "EnemyHp.h"
#include"Task/Task.h"
EnemyHp::EnemyHp(const CVector2D& pos) :Task(eType_EnemyHp,(int)TaskPrio::Field)
{
	m_img = COPY_RESOURCE("EnemyHp", CImage);
	//ƒQ[ƒW‚Ì•
	int width = 1900;
	//ƒQ[ƒW‚Ì‚‚³
	int height = 25;
	//Œ»İ‚ÌHP
	int hp = 100;
	//Å‘åHP
	int max_hp = 100;
}
void EnemyHp::UpDate()
{
	//ƒQ[ƒW”wŒi(Ô)
	m_img.SetSize(width, height);
	m_img.SetRect(0, 64, width, 128);
	m_img.Draw();

	//ƒQ[ƒW‚Ì•‚ğŒvZ(—Î)
	int w = width * hp / max_hp;
	m_img.SetSize(w, height);
	m_img.SetRect(0, 0, w, 64);
	m_img.Draw();
}
void EnemyHp::Draw()
{

	m_img.Draw();
}