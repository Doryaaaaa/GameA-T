#pragma once
#include"../Task/ObjectBase.h"

class Trapp2 :public ObjectBase {
public:
	Trapp2(const CVector3D& pos);

	void Update();
	void Draw();
	void Collision(Task* b);
	bool Trappflag;
private:
	CImage m_img;
};
extern TexAnimData Trapp2_anim_data[];