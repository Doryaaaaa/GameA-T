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
	//���n�t���O
	bool m_is_ground;
	//�U���ԍ�
	int m_attack_no;
	float m_speed;
	void StateRun();
	void StateAttack();
	void StateSpeedUp();
	void StateSpeedDown();

public:
    Player(const CVector3D& pos);
    void Update();
    void Draw();
    void Collision(Base* b);


};
