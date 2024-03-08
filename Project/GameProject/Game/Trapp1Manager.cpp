#include "Trapp1Manager.h"
#include "Trapp1.h"
Trapp1Manager::Trapp1Manager() : Base(eType_Trapp1Manager)
{
	//���o���܂ł̎���
	m_cnt = 0;
}

void Trapp1Manager::Update()
{
	m_cnt--;
	//���o��
	if (m_cnt <= 0) {
		//X����12�`1800�̊ԂŃ����_��
		Base::Add(new Trapp1(CVector2D(Utility::Rand(12.0f, 1800.0f), 0)));
		//���̏o������
		m_cnt = Utility::Rand(120, 360);
	}
}