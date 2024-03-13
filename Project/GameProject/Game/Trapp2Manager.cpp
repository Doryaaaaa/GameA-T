#include "Trapp2Manager.h"
#include "Trapp2.h"
Trapp2Manager::Trapp2Manager() : ObjectBase(eType_Trapp2Manager)
{
	//肉出現までの時間
	m_cnt = 0;
}

void Trapp2Manager::Update()
{
	m_cnt--;
	//肉出現
	if (m_cnt <= 0) {
		//X軸は12～1800の間でランダム
		(new Trapp2(CVector3D(m_scroll.x + Utility::Rand(2000.0f, 2500.0f), 1000,Utility::Rand(-390.0f, 0.0f))));
		//次の出現時間
		m_cnt = Utility::Rand(40, 120);
	}
}