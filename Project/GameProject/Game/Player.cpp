#include "Player.h"

Player::Player(const CVector3D& pos) :Base(eType_Player) {
    m_img = COPY_RESOURCE("Player", CImage);
    m_pos = pos;
    //m_img.ChangeAnimation(0);
}

void Player::Update() {
    //m_img.UpdateAnimation();
    //移動スピード
    const int move_speed = 4;
    //ジャンプ力
    const float jump_pow = 15;
    //上移動
    if (HOLD(CInput::eUp)) {
        m_pos.y -= move_speed;
    }
    //下移動
    if (HOLD(CInput::eDown)) {
        m_pos.y += move_speed;
    }
    //スペースでジャンプ
    /*if (m_is_ground && PUSH(CInput::eButton5)) {
        m_vec.y = -jump_pow;
        m_is_ground = false;
    }*/
}
void Player::Draw() {
   // m_img.SetPos(GetScreenPos(m_pos));
    m_img.Draw();
}