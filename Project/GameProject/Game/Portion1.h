#pragma once
#include "../Base/Base.h"

class Portion1 :public Base{
	public:
		CImage m_img;
	private:
		Portion1(const CVector3D& pos);
		void Update();
		void Drow();
};
