#include "Player.h"
#include "Field.h"


Player::Player(const CVector3D& pos) :Base(eType_Player) {
    m_img = COPY_RESOURCE("Player", CImage);
   // m_img.ChangeAnimation(0);
    m_pos = pos;
    //サイズ設定
    m_img.SetSize(200, 200);
    //中心位置設定
    m_img.SetCenter(100, 100);
    //当たり判定
    m_rect = CRect(-50, -50, 50, 50);
    //通常状態(常に走り)へ
    m_state = eState_Run;
    //着地フラグ
    m_is_ground = false;
    //攻撃番号
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
        //通常状態(常に走り)
        case eState_Run:
            StateRun();
            break;
        //攻撃状態
        case eState_Attack:
            StateAttack();
            break;
            //加速状態
        case eState_SpeedUp:
            StateSpeedUp();
            break;
            //減速状態
        case eState_SpeedDown:
            StateSpeedDown();
            break;
    }
    
    //落ちていたら落下中状態へ移行
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //重力による落下
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

void Player::StateRun() {
    //移動スピード
    const int move_speed = 4;
    //ジャンプ力
    const float jump_pow = 15;

    //上移動（上キー）
    if (HOLD(CInput::eUp)) {
        m_pos.z -= move_speed;
    }

    //下移動（下キー）
    if (HOLD(CInput::eDown)) {
        m_pos.z += move_speed;
    }
    /*
    //攻撃(S)
    if (PUSH(CInput::eButton)) {
        //攻撃状態へ移行
        m_state = eState_Attack;
        m_attack_no++;
    }
*/
    //ジャンプ(スペース)
    /*if (m_is_ground && PUSH(CInput::eButton5)) {
        m_vec.y = -jump_pow;
        m_is_ground = false;
    }*/

    m_img.ChangeAnimation(0);
}