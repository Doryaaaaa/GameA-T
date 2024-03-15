#pragma once
#include"../Task/Task.h"
#include"Task/ObjectBase.h"
//スイッチ
class Trapp1 :public ObjectBase {
public:
	Trapp1(const CVector3D& pos);

	void Update();
	void Draw();
	void Collision(Task* b);
	bool Trappflag;
private:
	CImage m_img;
	int m_cnt;
	int m_rcnt;
};
extern TexAnimData Trapp1_anim_data[];