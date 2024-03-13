#include "EnemyHp.h"
#include"Task/Task.h"
EnemyHp::EnemyHp(const CVector2D& pos) :Task(eType_EnemyHp,(int)TaskPrio::Field)
{
	m_pos = pos;
	m_img = COPY_RESOURCE("EnemyHp", CImage);
	//ƒQ[ƒW‚Ì•
	width = 1900;
	//ƒQ[ƒW‚Ì‚‚³
	height = 25;
	//Œ»İ‚ÌHP
	hp = 100;
	//Å‘åHP
	max_hp = 100;
}
void EnemyHp::Update()
{
	//ƒQ[ƒW”wŒi(Ô)
	
}
void EnemyHp::Draw()
{
	m_img.SetSize(width, height);
	m_img.SetRect(0, 64, width, 128);
	m_img.Draw();

	//ƒQ[ƒW‚Ì•‚ğŒvZ(—Î)
	int w = width * hp / max_hp;
	m_img.SetSize(w, height);
	m_img.SetRect(0, 0, w, 64);
	m_img.Draw();
	m_img.SetPos(m_pos);
}