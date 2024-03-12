#pragma once

#include"../Task/ObjectBase.h"

class Effect :public ObjectBase {
private:
	CImage m_img;
public:
	Effect(const char* name, const CVector2D& pos, bool flip);
	void Update();
	void Draw();
};
