#include "Player.h"
Player::Player(const CVector2D& pos) :Base(eType_Player) {
    m_img = COPY_RESOURCE("Player",CImage);
    m_pos = pos;
    //m_img.ChangeAnimation(0);
  //  m_img.SetCenter(32 / 2, 32 / 2);
}
void Player::Update() {
    //m_img.UpdateAnimation();
    const int move_speed = 4;
    if (HOLD(CInput::eRight)) {
        m_pos.x += move_speed;
    }
    if (HOLD(CInput::eLeft)) {
        m_pos.x -= move_speed;
    }
}
void Player::Draw() {
    m_img.SetPos(GetScreenPos(m_pos));
    m_img.Draw();
}