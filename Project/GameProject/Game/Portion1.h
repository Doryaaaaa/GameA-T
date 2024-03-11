#pragma once
#include "../Base/Base.h"

class PortionManager : public Base {
private:
	int m_cnt;
public:
	PortionManager();
	void Update();
};

//‰Á‘¬–ò
class Portion1 :public Base{
private:
		CImage m_img;
		bool m_is_portion1;

public:
		Portion1(const CVector3D& pos);
		void Update();
		void Drow();

};



