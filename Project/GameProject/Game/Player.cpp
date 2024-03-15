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
    //弾のスピードと向き
    const int move_speed = 100;
    m_pos.x += move_speed;
    //スクロール値＋数値分の座標を超えたら消える
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
    //サイズ設定
    m_img.SetSize(400, 400);
    //中心位置設定
    m_img.SetCenter(200, 380);
    //当たり判定
    m_rect = Rect3D(-100, -300,-30, 100, 0,30);
    //着地フラグ
    m_is_ground = false;
    //攻撃番号
    m_attack_no = rand();
    //加速度
    m_speed=0;
    //スクロール時間
    move_Scrollspeed=15;
    //効果時間
    waitcnt = 0;
    //移動制御用
    m_m=2;
    //バースト撃ち
    m_bcnt=0;
}

void Player::Update() {
   
    //移動スピード
    const int move_speed = 4;
    //ジャンプ力
    const float jump_pow = 15;
    if (m_Damage == true) {
        cnt++;
        if (cnt > 60) {
            m_Damage = false;
            cnt = 0;
        }
    }
    //上移動（上キー）&&　スクリーン制限
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

    //下移動（下キー）
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

    //スクロールのスピード  
    m_pos.x += move_Scrollspeed;

    //加速処理
    if (m_speed > 0) {
        move_Scrollspeed += 1;
        if (waitcnt > 0) {
            waitcnt--;
        }
        
    }

    //減速処理
    else if (m_speed < 0) {
        move_Scrollspeed -= 1;
        if (waitcnt > 0) {
            waitcnt--;
        }
    }

    //効果時間が終わると元のスピードに戻る
    if (waitcnt==0) {
        move_Scrollspeed = 15;
    }
    


    //攻撃(マウス左ボタン)
    if (PUSH(CInput::eMouseL)) {      
        (new Bullet(CVector3D(m_pos.x, m_pos.y - 150, m_pos.z), eType_Bullet, m_attack_no));

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
   // DrawRect();
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

    case eType_Portion1:
       //Portion1Manager型へキャスト、型変換出来たら
       if (Portion1* P1 = dynamic_cast<Portion1*>(b)) {
           //プレイヤーが加速ポーションと当たったら
           if (ObjectBase::CollisionRect(this, P1)) {
               //アイテムが消える
               P1->Kill();
               //加速
               m_speed = 1;
               //効果時間
               waitcnt = 20;
           }
       }

    case eType_Trapp3:
        //Trapp3型へキャスト、型変換出来たら
        if (Trapp3* T3 = dynamic_cast<Trapp3*>(b)) {
            //プレイヤーが針トラップと当たったら
            if (ObjectBase::CollisionRect(this, T3)) {
                //ジャンプ中なら
                if (!m_is_ground) {
                   
                }
                //ダメージアニメーション
                m_img.ChangeAnimation(1);
                if (m_Damage == false) {

           
                //減速
                m_speed = -1;
                //効果時間
                waitcnt = 20;
                m_Damage = true;
                }
                //アニメーションが終了したら
                if (m_img.CheckAnimationEnd()) {
                    m_img.ChangeAnimation(0);
                }
            }
        }

    case eType_Trapp4:
        //Trapp4型へキャスト、型変換出来たら
        if (Trapp4* T4 = dynamic_cast<Trapp4*>(b)) {
            //プレイヤーが落とし穴に当たったら
            if (ObjectBase::CollisionRect(this, T4)) {
                //ジャンプ中なら
                if (!m_is_ground) {

                }
              


                    //ダメージアニメーション
                    m_img.ChangeAnimation(1);
                    if (m_Damage == false) {
                    //減速
                    m_speed = -1;
                    //効果時間
                    waitcnt = 20;
                    m_Damage = true;
            
                }
                //アニメーションが終了したら
                if (m_img.CheckAnimationEnd()) {
                    m_img.ChangeAnimation(0);
                }
            }
        }


   }

}

