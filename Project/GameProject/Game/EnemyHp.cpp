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
	
	
}
void EnemyHp::Draw()
{
	//ƒQ[ƒW”wŒi(Ô)
	m_img.SetSize(width, height);
	m_img.SetRect(0, 25, width, 50);
	m_img.Draw();

	//ƒQ[ƒW‚Ì•‚ğŒvZ(—Î)
	int w = width * hp / max_hp;
	m_img.SetSize(w, height);
	m_img.SetRect(0, 0, w, 25);
	m_img.Draw();
	m_img.SetPos(m_pos);
}