#pragma once
#include "../Task/ObjectBase.h"

class Trapp2Manager : public ObjectBase {
private:
	int m_cnt;
public:
	Trapp2Manager();
	void Update();
};