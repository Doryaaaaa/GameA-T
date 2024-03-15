#pragma once
#include"../Task/ObjectBase.h"

class Trapp3 :public ObjectBase {
public:
	Trapp3(const CVector3D& pos);
	void Collision(Task* b);
	void Update();
	void Draw();
private:
	CImage m_img;
	bool m_Damage;
	int cnt;
};
extern TexAnimData Trapp3_anim_data[];

class Trapp4 :public ObjectBase {
public:
	Trapp4(const CVector3D& pos);
	void Collision(Task* b);
	void Update();
	void Draw();
private:
	CImage m_img;
	bool m_Damage;
	int cnt;
};