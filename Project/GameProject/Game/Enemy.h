#pragma once
#include"../Base/Base.h"

class Enemy :public Base{
public:
	Enemy(const CVector3D&pos);

	void Update();
	void Draw();
private:
	CImage m_img;
	int m_hp;
};
extern TexAnimData enemy_anim_data[];