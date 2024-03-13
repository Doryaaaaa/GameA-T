#pragma once

#include "../Task/ObjectBase.h"

class Bullet : public ObjectBase {
private:
	CImage m_img;
	int m_attack_no;
	int m_cnt;
public:
	Bullet(const CVector2D& pos, bool flip, int type, int attack_no);
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
	float m_speed;

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
