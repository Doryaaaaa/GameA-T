#include "Trapp2Manager.h"
#include "Trapp2.h"
Trapp2Manager::Trapp2Manager() : ObjectBase(eType_Trapp2Manager)
{
	//���o���܂ł̎���
	m_cnt = 0;
}

void Trapp2Manager::Update()
{
	m_cnt--;
	//���o��
	if (m_cnt <= 0) {
		//X����12�`1800�̊ԂŃ����_��
		(new Trapp2(CVector3D(m_scroll.x + Utility::Rand(2000.0f, 2500.0f), 1000,Utility::Rand(-390.0f, 0.0f))));
		//���̏o������
		m_cnt = Utility::Rand(40, 120);
	}
}