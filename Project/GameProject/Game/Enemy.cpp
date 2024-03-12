#include"Enemy.h"
#include"Field.h"
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
	m_img.SetCenter(200,380);
	m_is_ground = false;
	m_rect = Rect3D(-100, -400,-10, 100, 0,10);

}


void Enemy::Update() {
	const int move_speed = 4;
	const int move_Scrollspeed = 15;
	m_pos.x += move_Scrollspeed;
	//m_cnt=0;
	m_cnt++;
	/*カウントが０より小さい場合カウントがプラスされる
	if (m_cnt<0) {
		m_cnt++;
	}
	//カウントが０より大きく座標が０以下の場合手前に来る
	if (m_cnt > 0 && m_pos.z < 0) {
		m_pos.z += move_speed;
	}
	//カウントが０より大きい場合カウントがマイナスされる
	if (m_cnt > 0) {
		m_cnt--;
	}
	//カウントが０より小さく座標がー３９０より大きい場合奥に行く
	if (m_cnt < 0&& m_pos.z > -390) {
		m_pos.z -= move_speed;
	}
	
    if (m_cnt==0) {
		m_cnt =-180+rand()% 360;
	}*/
	
	if (m_cnt==180) {
		cnt = 1 + rand() % 3;
	}
	if (m_cnt > 200) {
		m_cnt = 0;
	}
	switch (cnt)
	{
	case 1:
		m_pos.z = 0;
		break;
	case 2:
		m_pos.z = -170;
		break;
	case 3:
		m_pos.z = -340;
		break;
	}
	


	m_vec.y += GRAVITY;
	m_pos += m_vec;
	m_img.UpdateAnimation();

}
void Enemy::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	Utility::DrawQuad(
		GetScreenPos(m_pos),
		//矩形設定
		CVector2D(200, 16),
		CVector4D(1, 0, 0, 0.5f));

	DrawRect();
}
void Enemy::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Field:
		//Field型へキャスト、型変換出来たら
		if (Field* f = dynamic_cast<Field*>(b)) {
			//地面より下に行ったら
			if (m_pos.y > f->GetGroundY()) {
				//地面の高さを戻す
				m_pos.y = f->GetGroundY();
				//落下速度リセット
				m_vec.y = 0;
				//設置フラグON
				m_is_ground = true;
			}
		}
	}
}