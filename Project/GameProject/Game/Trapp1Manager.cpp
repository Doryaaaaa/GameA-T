#include "Trapp1Manager.h"
#include "Trapp1.h"
Trapp1Manager::Trapp1Manager() : ObjectBase(eType_Trapp1Manager)
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
		(new Trapp1(CVector3D(m_scroll.x+Utility::Rand(2000.0f, 2500.0f),900,-390)));
		//���̏o������
		m_cnt = Utility::Rand(40, 120);
	}
}