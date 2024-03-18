#include"Enemy.h"
#include"Field.h"
#include"Player.h"
#include"Trapp3.h"
#include"Task/Task.h"
#include"Task/TaskManager.h"

TexAnim stand_by_anim[] = {
	{0,6},
    {1,6},
    {2,6},
    {3,6},
};

TexAnimData enemy_anim_data[] = {
	{stand_by_anim,sizeof(stand_by_anim) / sizeof(stand_by_anim[0])}
};
Enemy::Enemy(const CVector3D&pos, bool flip):ObjectBase(eType_Enemy) {
	m_pos = pos;
	m_hp = 100;
	m_img = COPY_RESOURCE("Enemy", CImage);
	m_img.SetSize(400, 400);
	m_img.ChangeAnimation(0);
	m_img.SetCenter(200,380);
	m_is_ground = false;
	m_rect = Rect3D(-200, -400,-400, 200, 0,0);
	m_hpGeag=new EnemyHp(CVector2D(0, 50));
	m_Damage = false;
	m_flip = flip;
	//
	m_isShadow = true;
	m_ShadowSize = 200;
	m_ShadowCenter = 100;
}


void Enemy::Update() {
	m_hpGeag->hp = m_hp;
	const int move_speed = 4;
	const int move_Scrollspeed = 15;
	m_pos.x += move_Scrollspeed;
	if (m_Damage==true) {
		cnt++;
		if (cnt>60) {
			m_Damage = false;
			cnt = 0;
		}
	}
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
	if (PUSH(CInput::eButton1)) {
		m_hp -= 10;
	}
	if (m_hp <= 0) {
		Kill();

	}
	m_pos += m_vec;
	m_img.UpdateAnimation();

}
void Enemy::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.SetFlipH(m_flip);
	m_img.Draw();
/*	Utility::DrawQuad(
		GetScreenPos(m_pos),
		//��`�ݒ�
		CVector2D(200, 16),
		CVector4D(1, 0, 0, 0.5f));*/

	//DrawRect();
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
		switch (b->m_type) {
		case eType_Trapp3://�g�Q
			if (Trapp3* P1 = dynamic_cast<Trapp3*>(b)) {
				if (ObjectBase::CollisionRect(this, P1)) {
					if (m_Damage==false) {
						m_hp -= 5;
						m_Damage = true;
				
					}
				}
				break;
			}
	}
		switch (b->m_type) {
		case eType_Trapp4://���Ƃ���
			if (Trapp4* P1 = dynamic_cast<Trapp4*>(b)) {
				if (ObjectBase::CollisionRect(this, P1)) {
					if (m_Damage == false) {
						m_hp -= 5;
						m_Damage = true;
					}
				}
				break;
			}
		}
		switch (b->m_type) {
		case eType_Bullet:
			if (Bullet* P1 = dynamic_cast<Bullet*>(b)) {
				if (ObjectBase::CollisionRect(this, P1)) {
					P1->Kill();
					m_hp -= 1;

				}
				break;
			}
		}
}
/*Enemywall::Enemywall(const CVector3D& pos) :ObjectBase(eType_Enemywall) {
	m_img = COPY_RESOURCE("Enemywall", CImage);
	m_pos = pos;
	m_img.SetSize(0, 0);
	m_img.SetCenter(200, 380);
	m_rect = Rect3D(10, 1000, 1000, -10, -1000, -1000);
}
void Enemywall::Update() {
	const int move_speed = 4;
	const int move_Scrollspeed = 15;
	m_pos.x += move_Scrollspeed;
	m_pos += m_vec;
	//m_vec.y += GRAVITY;
}
void Enemywall::Draw() {
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
		/*Utility::DrawQuad(
			GetScreenPos(m_pos),
			//��`�ݒ�
			CVector2D(200, 16),
			CVector4D(1, 0, 0, 0.5f));
			DrawRect();
}
void Enemywall::Collision(Task* b)
{
	switch (b->m_type) {
	case eType_Player:
		if (Player* P1 = dynamic_cast<Player*>(b)) {
			if (ObjectBase::CollisionRect(this, P1)) {
				m_speed = -1;
				//���ʎ���
				waitcnt = 20;
			}
			break;
		}
	}
}*/