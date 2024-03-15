#pragma once

#include "../Task/ObjectBase.h"

class Bullet : public ObjectBase {
private:
	CImage m_img;
	int m_attack_no;
	int m_cnt;
	int waitcnt;
public:
	Bullet(const CVector3D& pos, int type, int attack_no);
	void Update();
	void Draw();
	int GetAttackNo() {
		return m_attack_no;
	}
};

class Player :public ObjectBase {
private:
    CImage m_img;
	//着地フラグ
	bool m_is_ground;
	//攻撃番号
	int m_attack_no;
	//加速度
	int m_speed;
	//スクロールスピード
	int move_Scrollspeed;
	//効果時間
	float waitcnt;
	//移動制御
	int m_m;
	int cnt;
	bool m_Damage;
	int m_bcnt;

public:
    Player(const CVector3D& pos);
    void Update();
    void Draw();
    void Collision(Task* b);


};

extern TexAnimData player_anim_data[];
extern TexAnimData damage_anim_data[];
extern TexAnimData jumpup_anim_data[];
extern TexAnimData jumpdown_anim_data[];
extern TexAnimData bullet_anim_data[];
