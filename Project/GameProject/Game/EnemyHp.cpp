#include "EnemyHp.h"
#include"Task/Task.h"
EnemyHp::EnemyHp(const CVector2D& pos) :Task(eType_EnemyHp,(int)TaskPrio::Field)
{
	m_pos = pos;
	m_img = COPY_RESOURCE("EnemyHp", CImage);
	//�Q�[�W�̕�
	width = 1900;
	//�Q�[�W�̍���
	height = 25;
	//���݂�HP
	hp = 100;
	//�ő�HP
	max_hp = 100;
}
void EnemyHp::Update()
{
	//�Q�[�W�w�i(��)
	
}
void EnemyHp::Draw()
{
	m_img.SetSize(width, height);
	m_img.SetRect(0, 64, width, 128);
	m_img.Draw();

	//�Q�[�W�̕����v�Z(��)
	int w = width * hp / max_hp;
	m_img.SetSize(w, height);
	m_img.SetRect(0, 0, w, 64);
	m_img.Draw();
	m_img.SetPos(m_pos);
}