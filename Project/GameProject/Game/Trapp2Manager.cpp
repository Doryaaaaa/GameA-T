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
		
		}
		//次の出現時間
		m_cnt = Utility::Rand(60, 180);
	}
}