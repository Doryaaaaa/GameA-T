#pragma once
#include"../Base/Base.h"

class Trapp2 :public Base {
public:
	Trapp2(const CVector3D& pos);

	void Update();
	void Draw();
private:
	CImage m_img;
};