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
Enemy::Enemy(const CVector3D&pos):ObjectBase(eType_Enemy) {
	m_pos = pos;
	
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_img.SetSize(400, 400);
	m_img.ChangeAnimation(0);
	//m_img.SetCenter(200,400);
	//m_rect = CRect(-100, -400, 100, 0);

}


void Enemy::Update() {
	const int move_speed = 4;
	m_cnt++;
	if (m_cnt>100) {
		m_pos.y += move_speed;
	}
	else if(m_cnt>100) {
		m_pos.y += move_speed;
	}
	else if (m_cnt) {
		m_cnt = 0;
	}

	m_img.UpdateAnimation();
}
void Enemy::Draw() {
	m_img.SetPos(m_pos.x,m_pos.y);
	m_img.Draw();
	DrawRect();
}