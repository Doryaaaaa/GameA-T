#pragma once
#include "../Task/ObjectBase.h"

class Trapp2Manager : public ObjectBase {
private:
	int m_cnt;
	int m_rcnt;
public:
	Trapp2Manager();
	void Update();
};