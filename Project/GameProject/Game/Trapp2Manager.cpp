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
		//�ǂ��ɔz�u���邽�߂̃����_���Ȑ���
		
		}
		//���̏o������
		m_cnt = Utility::Rand(60, 180);
	}
}