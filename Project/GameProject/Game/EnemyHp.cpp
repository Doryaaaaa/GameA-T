#include "EnemyHp.h"
#include"Task/Task.h"
EnemyHp::EnemyHp(const CVector2D& pos) :Task(eType_EnemyHp,(int)TaskPrio::Field)
{
	m_img = COPY_RESOURCE("EnemyHp", CImage);
	//Q[WĚ
	int width = 1900;
	//Q[WĚł
	int height = 25;
	//ťÝĚHP
	int hp = 100;
	//ĹĺHP
	int max_hp = 100;
}
void EnemyHp::UpDate()
{
	//Q[Wwi(Ô)
	m_img.SetSize(width, height);
	m_img.SetRect(0, 64, width, 128);
	m_img.Draw();

	//Q[WĚđvZ(Î)
	int w = width * hp / max_hp;
	m_img.SetSize(w, height);
	m_img.SetRect(0, 0, w, 64);
	m_img.Draw();
}
void EnemyHp::Draw()
{

	m_img.Draw();
}