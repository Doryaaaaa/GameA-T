#include "EnemyHp.h"
#include"Task/Task.h"
EnemyHp::EnemyHp(const CVector2D& pos) :Task(eType_EnemyHp,(int)TaskPrio::Field)
{
	m_pos = pos;
	m_img = COPY_RESOURCE("EnemyHp", CImage);
	//Q[WĚ
	width = 1900;
	//Q[WĚł
	height = 25;
	//ťÝĚHP
	hp = 100;
	//ĹĺHP
	max_hp = 100;
}
void EnemyHp::Update()
{
}
void EnemyHp::Draw()
{
	//Q[Wwi(Ô)
	m_img.SetSize(width, height);
	m_img.SetRect(0, 25, width, 50);
	m_img.Draw();

	//Q[WĚđvZ(Î)
	int w = width * hp / max_hp;
	m_img.SetSize(w, height);
	m_img.SetRect(0, 0, w, 25);
	m_img.Draw();
	m_img.SetPos(m_pos);
}