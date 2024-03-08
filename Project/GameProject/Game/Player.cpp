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
    //サイズ設定
    m_img.SetSize(400, 400);
    //中心位置設定
    m_img.SetCenter(200, 400);
    //当たり判定
    m_rect = CRect(-100, 10, 100, 0);
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
   
    //移動スピード
    const int move_speed = 4;
    //ジャンプ力
    const float jump_pow = 15;

    //上移動（上キー）
    if (HOLD(CInput::eButton6)) {
        m_pos.z -= move_speed;
    }

    //下移動（下キー）
    if (HOLD(CInput::eButton7)) {
        m_pos.z += move_speed;
    }
    const int move_Scrollspeed = 30;
    m_pos.x += move_Scrollspeed;
    /*
    //攻撃(左クリック)
    if (PUSH(CInput::eButton8||PUSH(CInput::eMouseL)) {
        //攻撃状態へ移行
        m_img.ChangeAnimation(1);
    }
*/
//ジャンプ(スペース)
    if (m_is_ground && PUSH(CInput::eButton5)) {
        m_vec.y = -jump_pow;
        m_is_ground = false;
        //ジャンプ中なら
        if (!m_is_ground) {
            if (m_vec.y < 0)
                //上昇アニメーション
                m_img.ChangeAnimation(2, false);
            else
                //下降アニメーション
                m_img.ChangeAnimation(3, true);
        }
        
    }

    if (m_is_ground) {
        m_img.ChangeAnimation(0);
    }
    
    
    //落ちていたら落下中状態へ移行
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //重力による落下
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

