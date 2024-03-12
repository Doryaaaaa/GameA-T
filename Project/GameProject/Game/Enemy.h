#pragma once
#include"../Task/ObjectBase.h"

class Enemy :public ObjectBase{
public:
	Enemy(const CVector3D&pos);

	void Update();
	void Draw();
private:
	CImage m_img;
	int m_hp;
	int m_cnt;
};
extern TexAnimData enemy_anim_data[];