#include "Player.h"
#include "Field.h"


Player::Player(const CVector3D& pos) :Base(eType_Player) {
    m_img = COPY_RESOURCE("Player", CImage);
   // m_img.ChangeAnimation(0);
    m_pos = pos;
    //�T�C�Y�ݒ�
    m_img.SetSize(200, 200);
    //���S�ʒu�ݒ�
    m_img.SetCenter(100, 100);
    //�����蔻��
    m_rect = CRect(-50, -50, 50, 50);
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
    switch (m_state) {
        //�ʏ���(��ɑ���)
        case eState_Run:
            StateRun();
            break;
        //�U�����
        case eState_Attack:
            StateAttack();
            break;
            //�������
        case eState_SpeedUp:
            StateSpeedUp();
            break;
            //�������
        case eState_SpeedDown:
            StateSpeedDown();
            break;
    }
    
    //�����Ă����痎������Ԃֈڍs
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //�d�͂ɂ�闎��
    m_vec.y += GRAVITY;
    m_pos += m_vec;
    
    //m_img.UpdateAnimation();
}
void Player::Draw() {
    m_img.SetPos(GetScreenPos(m_pos));
    m_img.Draw();
    //DrawRect();
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

void Player::StateRun() {
    //�ړ��X�s�[�h
    const int move_speed = 4;
    //�W�����v��
    const float jump_pow = 15;

    //��ړ��i��L�[�j
    if (HOLD(CInput::eUp)) {
        m_pos.z -= move_speed;
    }

    //���ړ��i���L�[�j
    if (HOLD(CInput::eDown)) {
        m_pos.z += move_speed;
    }
    /*
    //�U��(S)
    if (PUSH(CInput::eButton)) {
        //�U����Ԃֈڍs
        m_state = eState_Attack;
        m_attack_no++;
    }
*/
    //�W�����v(�X�y�[�X)
    /*if (m_is_ground && PUSH(CInput::eButton5)) {
        m_vec.y = -jump_pow;
        m_is_ground = false;
    }*/

    m_img.ChangeAnimation(0);
}