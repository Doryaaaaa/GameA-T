#pragma once
#include "../Task/ObjectBase.h"

class Trapp1Manager : public ObjectBase {
private:
	int m_cnt;
	
public:
	Trapp1Manager();
	void Update();
};