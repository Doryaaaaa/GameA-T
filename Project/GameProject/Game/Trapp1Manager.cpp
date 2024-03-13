#include "Trapp1Manager.h"
#include "Trapp1.h"
Trapp1Manager::Trapp1Manager() : ObjectBase(eType_Trapp1Manager)
{
	//肉出現までの時間
	m_cnt = 0;
}

void Trapp1Manager::Update()
{
	m_cnt--;
	//肉出現
	if (m_cnt <= 0) {
		//X軸は12～1800の間でランダム
		(new Trapp1(CVector3D(m_scroll.x+Utility::Rand(2000.0f, 2500.0f),900,-390)));
		//次の出現時間
		m_cnt = Utility::Rand(40, 120);
	}
}