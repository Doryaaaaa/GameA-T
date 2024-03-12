#include "Player.h"
#include "Field.h"
#include "Portion1.h"
#include "Task/TaskManager.h"
#include "Task/Task.h"

Bullet::Bullet(const CVector2D& pos, bool flip, int type, int attack_no) :ObjectBase(eType_Bullet) {
    m_img = COPY_RESOURCE("Effect_Bullet", CImage);
    m_pos = pos;
    m_img.SetSize(50, 50);
    m_img.SetCenter(25, 25);
    m_rect = Rect3D(-100, -300, -10, 100, 0, 10);
    m_attack_no = attack_no;
    m_cnt = 0;
}
void Bullet::Update() {
    //玉のスピードと向き
    const int move_speed = 10;
    m_pos.x -= move_speed;
    //スクリーンの端までいくと消える
    if (m_pos.x>m_scroll.x) {
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
    //サイズ設定
    m_img.SetSize(400, 400);
    //中心位置設定
    m_img.SetCenter(200, 380);
    //当たり判定
    m_rect = Rect3D(-100, -300,-10, 100, 0,10);
    //着地フラグ
    m_is_ground = false;
    //攻撃番号
    m_attack_no = rand();
    //加速度
    m_speed=0;

}

//後で消す
void Player::StateSpeedUp() {
    if (m_state = eState_SpeedUp) {
        m_speed += 1;
    }

}
//後で消す
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

    //上移動（上キー）&&　スクリーン制限
    if (HOLD(CInput::eButton6) && m_pos.z>-390) {
        
        m_pos.z -= move_speed;
    }

    //下移動（下キー）
    if (HOLD(CInput::eButton7) && m_pos.z < -0) {
        m_pos.z += move_speed;
    }

    //スクロールのスピード
   
    const int move_Scrollspeed = 15;
    m_pos.x += move_Scrollspeed;

    
    //攻撃(左クリック)
    if (HOLD(CInput::eMouseL)) {
        //(new Bullet(CVector3D(m_pos)));
    }

//ジャンプ(スペース)
    if (m_is_ground && PUSH(CInput::eButton5)) {
        m_vec.y = -jump_pow;
        m_is_ground = false;
        //ジャンプ中なら
        if (!m_is_ground) {
            
        }
        
    }

    if (m_is_ground) {
        m_img.ChangeAnimation(0);
    }
    else {
        if (m_vec.y < 0)
            //上昇アニメーション
            m_img.ChangeAnimation(2, false);
        else
            //下降アニメーション
            m_img.ChangeAnimation(3, true);
    }
    
    
    //落ちていたら落下中状態へ移行
    if (m_is_ground && m_vec.y > GRAVITY * 4)
        m_is_ground = false;
    //重力による落下
    m_vec.y += GRAVITY;
    m_pos += m_vec;

    //スクリーンの左の方に配置
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
    DrawRect();
}

void Player::Collision(Task* b)
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
   switch (b->m_type) {
   case eType_Portion1Manager:
       //Portion1Manager型へキャスト、型変換出来たら
       if (Portion1Manager* P1 = dynamic_cast<Portion1Manager*>(b)) {
           //プレイヤーがアイテムと当たったら
           if (ObjectBase::CollisionRect(this, P1)) {
               //アイテムが消える
               P1->Kill();
           }
       }
   }
   
}

