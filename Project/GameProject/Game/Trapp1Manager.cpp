#include "Trapp1Manager.h"
#include "Trapp1.h"
Trapp1Manager::Trapp1Manager() : Base(eType_Trapp1Manager)
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
		Base::Add(new Trapp1(CVector2D(Utility::Rand(2000.0f, 2500.0f), Utility::Rand(500.0f, 1080.0f))));
		//次の出現時間
		m_cnt = Utility::Rand(120, 360);
	}
}