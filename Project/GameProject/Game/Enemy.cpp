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
	/*�J�E���g���O��菬�����ꍇ�J�E���g���v���X�����
	if (m_cnt<0) {
		m_cnt++;
	}
	//�J�E���g���O���傫�����W���O�ȉ��̏ꍇ��O�ɗ���
	if (m_cnt > 0 && m_pos.z < 0) {
		m_pos.z += move_speed;
	}
	//�J�E���g���O���傫���ꍇ�J�E���g���}�C�i�X�����
	if (m_cnt > 0) {
		m_cnt--;
	}
	//�J�E���g���O��菬�������W���[�R�X�O���傫���ꍇ���ɍs��
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
		//��`�ݒ�
		CVector2D(200, 16),
		CVector4D(1, 0, 0, 0.5f));

	DrawRect();
}
void Enemy::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Field:
		//Field�^�փL���X�g�A�^�ϊ��o������
		if (Field* f = dynamic_cast<Field*>(b)) {
			//�n�ʂ�艺�ɍs������
			if (m_pos.y > f->GetGroundY()) {
				//�n�ʂ̍�����߂�
				m_pos.y = f->GetGroundY();
				//�������x���Z�b�g
				m_vec.y = 0;
				//�ݒu�t���OON
				m_is_ground = true;
			}
		}
	}
}