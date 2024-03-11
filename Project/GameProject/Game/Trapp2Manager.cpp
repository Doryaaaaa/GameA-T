#include "Trapp2Manager.h"
#include "Trapp2.h"
Trapp2Manager::Trapp2Manager() : Base(eType_Trapp2Manager)
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
		Base::Add(new Trapp2(CVector2D(m_scroll.x + Utility::Rand(2000.0f, 2500.0f), Utility::Rand(500.0f, 1080.0f))));
		//���̏o������
		m_cnt = Utility::Rand(40, 120);
	}
}