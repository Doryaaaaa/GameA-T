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
		//どこに配置するためのランダムな数字
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
		//次の出現時間
		m_cnt = Utility::Rand(60, 180);
	}
}