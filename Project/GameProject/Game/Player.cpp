#include "Player.h"
#include "Field.h"

TexAnim run_by_anim[] = {
    {0,6},
    {1,6},
    {2,6},
    {3,6},
    {4,6},
    {5,6},
};

TexAnim damage_by_anim[] = {
    {20,6},
    {21,6},   
};

TexAnim jumpup_by_anim[] = {
    {40,6},

};

TexAnim jumpdown_by_anim[] = {
    {41,6},

};

TexAnimData player_anim_data[] = {
      ANIMDATA(run_by_anim),
      ANIMDATA(damage_by_anim),
      ANIMDATA(jumpup_by_anim),
      ANIMDATA(jumpdown_by_anim),
};

Player::Player(const CVector3D& pos) :Base(eType_Player) {
    m_img = COPY_RESOURCE("Player", CImage);
    m_img.ChangeAnimation(0);
    m_pos = pos;
    //�T�C�Y�ݒ�
    m_img.SetSize(400, 400);
    //���S�ʒu�ݒ�
    m_img.SetCenter(200, 400);
    //�����蔻��
    m_rect = CRect(-100, 10, 100, 0);
    //�ʏ���(��ɑ���)��
    m_state = eState_Run;
    //���n�t���O
    m_is_ground = false;
    //�U���ԍ�
    m_attack_no = rand();
    m_speed=0;

}

void Player::StateAttack() {

}

void Player::StateSpeedUp() {
    if (m_state = eState_SpeedUp) {
        m_speed += 1;
    }

}

void Player::StateSpeedDown() {
    if (m_state = eState_SpeedDown) {
        m_speed -= 1;
    }
}

void Player::Update() {
   
    //�ړ��X�s�[�h
    const int move_speed = 4;
    //�W�����v��
    const float jump_pow = 15;

    //��ړ��i��L�[�j
    if (HOLD(CInput::eButton6)) {
        m_pos.z -= move_speed;
    }

    //���ړ��i���L�[�j
    if (HOLD(CInput::eButton7)) {
        m_pos.z += move_speed;
    }
    const int move_Scrollspeed = 30;
    m_pos.x += move_Scrollspeed;
    /*
    //�U��(���N���b�N)
    if (PUSH(CInput::eButton8||PUSH(CInput::eMouseL)) {
        //�U����Ԃֈڍs
        m_img.ChangeAnimation(1);
    }
*/
//�W�����v(�X�y�[�X)
    if (m_is_ground && PUSH(CInput::eButton5)) {
        m_vec.y = -jump_pow;
        m_is_ground = false;
        //�W�����v���Ȃ�
        if (!m_is_ground) {
            if (m_vec.y < 0)
                //�㏸�A�j���[�V����
                m_img.ChangeAnimation(2, false);
            else
                //���~�A�j���[�V����
                m_img.ChangeAnimation(3, true);
        }
        
    }

    if (m_is_ground) {
        m_img.ChangeAnimation(0);
    }
    
    
    //�����Ă����痎������Ԃֈڍs
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //�d�͂ɂ�闎��
    m_vec.y += GRAVITY;
    m_pos += m_vec;

    m_scroll.x = m_pos.x - 1920 / 2;

    
    m_img.UpdateAnimation();
}
void Player::Draw() {
    m_img.SetPos(GetScreenPos(m_pos));
    m_img.Draw();
    Utility::DrawQuad(
        GetScreenPos(m_pos),
        CVector2D(16,16),
        CVector4D(1, 0, 0, 0.5f));
    DrawRect();
}

void Player::Collision(Base* b)
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

