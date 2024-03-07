#include"Enemy.h"
TexAnim stand_by_anim[] = {
	{0,6},
    {1,6},
    {2,6},
    {3,6},
};
TexAnimData enemy_anim_data[] = {
	{stand_by_anim,sizeof(stand_by_anim) / sizeof(stand_by_anim[0])}
};
Enemy::Enemy(const CVector3D&pos):Base(eType_Enemy) {
	m_img = COPY_RESOURCE("Enemy", CImage);
	
	m_img.ChangeAnimation(0);
//	m_img.SetCenter(500.0f,500.0f);
}


void Enemy::Update() {
	const int move_speed = 4;
	if (HOLD(CInput::eUp)) {
		m_pos.z += move_speed;
	}
	if (HOLD(CInput::eDown)) {
		m_pos.z -= move_speed;
	}
	m_img.UpdateAnimation();
}
void Enemy::Draw() {
	m_img.SetPos(m_pos.x,m_pos.y);
	m_img.Draw();
}