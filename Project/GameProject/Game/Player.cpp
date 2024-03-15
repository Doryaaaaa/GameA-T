#include "Player.h"
#include "Field.h"
#include "Portion1.h"
#include "Trapp1.h"
#include "Trapp3.h"
#include "Task/TaskManager.h"
#include "Task/Task.h"

TexAnim bullet_by_anim[] = {
    {0,6},
    {1,6},
    
};
TexAnimData bullet_anim_data[] = {
      ANIMDATA(bullet_by_anim),
      
};

Bullet::Bullet(const CVector3D& pos, int type, int attack_no) :ObjectBase(eType_Bullet) {
    m_img = COPY_RESOURCE("Bullet", CImage);
    m_img.ChangeAnimation(0);
    m_pos = pos;
    m_img.SetSize(50, 50);
    m_img.SetCenter(25, 25);
    m_rect = Rect3D(-25, -25, -15, 25, 25, 15);
    m_attack_no = attack_no;
    m_cnt = 0;

}
void Bullet::Update() {
    //�e�̃X�s�[�h�ƌ���
    const int move_speed = 100;
    m_pos.x += move_speed;
    //�X�N���[���l�{���l���̍��W�𒴂����������
    if (m_pos.x> m_scroll.x+2500) {
        Kill();
    }

}
void Bullet::Draw() {
    m_img.SetPos(GetScreenPos(m_pos));
    m_img.Draw();
    DrawRect();
}




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

Player::Player(const CVector3D& pos) :ObjectBase(eType_Player) {
    m_img = COPY_RESOURCE("Player", CImage);
    m_img.ChangeAnimation(0);
    m_pos = pos;
    //�T�C�Y�ݒ�
    m_img.SetSize(400, 400);
    //���S�ʒu�ݒ�
    m_img.SetCenter(200, 380);
    //�����蔻��
    m_rect = Rect3D(-100, -300,-30, 100, 0,30);
    //���n�t���O
    m_is_ground = false;
    //�U���ԍ�
    m_attack_no = rand();
    //�����x
    m_speed=0;
    //�X�N���[������
    move_Scrollspeed=15;
    //���ʎ���
    waitcnt = 0;
    //�ړ�����p
    m_m=2;
    //�o�[�X�g����
    m_bcnt=0;
}

void Player::Update() {
   
    //�ړ��X�s�[�h
    const int move_speed = 4;
    //�W�����v��
    const float jump_pow = 15;
    if (m_Damage == true) {
        cnt++;
        if (cnt > 60) {
            m_Damage = false;
            cnt = 0;
        }
    }
    //��ړ��i��L�[�j&&�@�X�N���[������
    if (PUSH(CInput::eButton6) && m_pos.z>-390) {
        m_m += 1;
        switch (m_m)
        {
        case 0:
            m_m = 1;
            break;
        case 1:
            m_pos.z = 0;
            break;
        case 2:
            m_pos.z = -170;
            break;
        case 3:
            m_pos.z = -340;
            break;
        case 4:
            m_m = 3;
            break;
        }
    }

    //���ړ��i���L�[�j
    if (PUSH(CInput::eButton7) && m_pos.z < -0) {
        m_m -= 1;
        switch (m_m)
        {
        case 0:
            m_m = 1;
            break;
        case 1:
            m_pos.z = 0;
            break;
        case 2:
            m_pos.z = -170;
            break;
        case 3:
            m_pos.z = -340;
            break;
        case 4:
            m_m = 3;
            break;
        }
    }

    //�X�N���[���̃X�s�[�h  
    m_pos.x += move_Scrollspeed;

    //��������
    if (m_speed > 0) {
        move_Scrollspeed += 1;
        if (waitcnt > 0) {
            waitcnt--;
        }
        
    }

    //��������
    else if (m_speed < 0) {
        move_Scrollspeed -= 1;
        if (waitcnt > 0) {
            waitcnt--;
        }
    }

    //���ʎ��Ԃ��I���ƌ��̃X�s�[�h�ɖ߂�
    if (waitcnt==0) {
        move_Scrollspeed = 15;
    }
    


    //�U��(�}�E�X���{�^��)
    if (PUSH(CInput::eMouseL)) {      
        (new Bullet(CVector3D(m_pos.x, m_pos.y - 150, m_pos.z), eType_Bullet, m_attack_no));

    }

//�W�����v(�X�y�[�X)
    if (m_is_ground && PUSH(CInput::eButton5)) {
        m_vec.y = -jump_pow;
        m_is_ground = false;
        //�W�����v���Ȃ�
        if (!m_is_ground) {
            
        }
        
    }

    if (m_is_ground) {
        m_img.ChangeAnimation(0);
    }
    else {
        if (m_vec.y < 0)
            //�㏸�A�j���[�V����
            m_img.ChangeAnimation(2, false);
        else
            //���~�A�j���[�V����
            m_img.ChangeAnimation(3, true);
    }
    
    
    //�����Ă����痎������Ԃֈڍs
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //�d�͂ɂ�闎��
    m_vec.y += GRAVITY;
    m_pos += m_vec;

    //�X�N���[���̍��̕��ɔz�u
    m_scroll.x = m_pos.x - 1920 / 10;

    
    m_img.UpdateAnimation();
}
void Player::Draw() {
    m_img.SetPos(GetScreenPos(m_pos));
    m_img.Draw();


    /*Utility::DrawQuad(
        GetScreenPos(m_pos),

        CVector2D(16,16),
        CVector2D(16,16),
        CVector4D(1, 0, 0, 0.5f));
*/
   // DrawRect();
}

void Player::Collision(Task* b)
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

    case eType_Portion1:
       //Portion1Manager�^�փL���X�g�A�^�ϊ��o������
       if (Portion1* P1 = dynamic_cast<Portion1*>(b)) {
           //�v���C���[�������|�[�V�����Ɠ���������
           if (ObjectBase::CollisionRect(this, P1)) {
               //�A�C�e����������
               P1->Kill();
               //����
               m_speed = 1;
               //���ʎ���
               waitcnt = 20;
           }
       }

    case eType_Trapp3:
        //Trapp3�^�փL���X�g�A�^�ϊ��o������
        if (Trapp3* T3 = dynamic_cast<Trapp3*>(b)) {
            //�v���C���[���j�g���b�v�Ɠ���������
            if (ObjectBase::CollisionRect(this, T3)) {
                //�W�����v���Ȃ�
                if (!m_is_ground) {
                   
                }
                //�_���[�W�A�j���[�V����
                m_img.ChangeAnimation(1);
                if (m_Damage == false) {

           
                //����
                m_speed = -1;
                //���ʎ���
                waitcnt = 20;
                m_Damage = true;
                }
                //�A�j���[�V�������I��������
                if (m_img.CheckAnimationEnd()) {
                    m_img.ChangeAnimation(0);
                }
            }
        }

    case eType_Trapp4:
        //Trapp4�^�փL���X�g�A�^�ϊ��o������
        if (Trapp4* T4 = dynamic_cast<Trapp4*>(b)) {
            //�v���C���[�����Ƃ����ɓ���������
            if (ObjectBase::CollisionRect(this, T4)) {
                //�W�����v���Ȃ�
                if (!m_is_ground) {

                }
              


                    //�_���[�W�A�j���[�V����
                    m_img.ChangeAnimation(1);
                    if (m_Damage == false) {
                    //����
                    m_speed = -1;
                    //���ʎ���
                    waitcnt = 20;
                    m_Damage = true;
            
                }
                //�A�j���[�V�������I��������
                if (m_img.CheckAnimationEnd()) {
                    m_img.ChangeAnimation(0);
                }
            }
        }


   }

}

