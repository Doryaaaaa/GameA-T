#pragma once
#include"../Task/ObjectBase.h"

class Trapp2 :public ObjectBase {
public:
	Trapp2(const CVector3D& pos);

	void Update();
	void Draw();
private:
	CImage m_img;
};