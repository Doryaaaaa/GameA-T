#pragma once
#include"../Task/ObjectBase.h"

class Trapp3 :public ObjectBase {
public:
	Trapp3(const CVector3D& pos);

	void Update();
	void Draw();
private:
	CImage m_img;
};