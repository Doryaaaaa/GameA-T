#include "Trapp1Manager.h"
#include "Trapp1.h"
#include "Trapp2.h"

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
		switch (rand()%2)
		{
		case 0:
			(new Trapp1(CVector3D(m_scroll.x + Utility::Rand(2000.0f, 2500.0f), 900, -390)));
			break;
		case 1:
			int m_rcnt;
			m_rcnt = Utility::Rand(0, 300);

			if (m_rcnt < 100) {
				//アイテム出現　上
				(new Trapp2(CVector3D(m_scroll.x + 2000, 1000, -310)));
			}
			else if (m_rcnt < 200) {
				//アイテム出現　真ん中
				(new Trapp2(CVector3D(m_scroll.x + 2000, 1000, -170)));
			}
			else {
				//アイテム出現 下
				(new Trapp2(CVector3D(m_scroll.x + 2000, 1000, -30)));
			}
			break;
			
		}

		//X軸は12～1800の間でランダム
		

		//次の出現時間
		m_cnt = Utility::Rand(40, 120);
	}
}