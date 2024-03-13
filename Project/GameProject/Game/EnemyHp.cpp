#include "EnemyHp.h"
EnemyHp::EnemyHp(const CVector2D& pos)
{
	m_img = COPY_RESOURCE("EnemyHp", CImage);
	//ゲージの幅
	int width = 1900;
	//ゲージの高さ
	int height = 25;
	//現在のHP
	int hp = 100;
	//最大HP
	int max_hp = 100;
}
void EnemyHp::UpDate()
{

}