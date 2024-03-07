#pragma once
#include "../Base/Base.h"
//‰Á‘¬–ò
class Portion1 :public Base{
private:
		CImage m_img;
		bool m_is_portion1;

public:
		Portion1(const CVector3D& pos);
		void Update();
		void Drow();

		void SetPortion1() {
			m_is_portion1 = true;
		}

		bool GetPortion1() {
			return m_is_portion1;
		}
};
