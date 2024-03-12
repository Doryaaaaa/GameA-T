#pragma once

#include "../Base/Base.h"
class Player :public Base {
private:
	enum {
		eState_Run,
		eState_Attack,
		eState_SpeedUp,
		eState_SpeedDown,
		
	};
	int m_state;
    CImage m_img;
	//着地フラグ
	bool m_is_ground;
	//攻撃番号
	int m_attack_no;
	//加速度
	float m_speed;
	void StateSpeedUp();
	void StateSpeedDown();

public:
    Player(const CVector3D& pos);
    void Update();
    void Draw();
    void Collision(Base* b);


};

extern TexAnimData player_anim_data[];
extern TexAnimData damage_anim_data[];
extern TexAnimData jumpup_anim_data[];
extern TexAnimData jumpdown_anim_data[];
