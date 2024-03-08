#pragma once
#include"../Base/Base.h"
//スイッチ
class Trapp1 :public Base {
public:
	Trapp1(const CVector3D& pos);

	void Update();
	void Draw();
private:
	CImage m_img;
};