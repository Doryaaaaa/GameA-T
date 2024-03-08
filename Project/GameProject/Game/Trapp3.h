#pragma once
#include"../Base/Base.h"

class Trapp3 :public Base {
public:
	Trapp3(const CVector3D& pos);

	void Update();
	void Draw();
private:
	CImage m_img;
};