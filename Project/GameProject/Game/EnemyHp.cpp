#include "EnemyHp.h"
EnemyHp::EnemyHp(const CVector2D& pos)
{
	m_img = COPY_RESOURCE("EnemyHp", CImage);
	//�Q�[�W�̕�
	int width = 1900;
	//�Q�[�W�̍���
	int height = 25;
	//���݂�HP
	int hp = 100;
	//�ő�HP
	int max_hp = 100;
}
void EnemyHp::UpDate()
{

}