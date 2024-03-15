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
		m_rcnt = Utility::Rand(0, 300);

		if (m_rcnt < 100) {
			//�A�C�e���o���@��
			(new Trapp2(CVector3D(m_scroll.x + 2000, 1000, -310)));
		}
		else if (m_rcnt < 200) {
			//�A�C�e���o���@�^��
			(new Trapp2(CVector3D(m_scroll.x + 2000, 1000, -170)));
		}
		else {
			//�A�C�e���o�� ��
			(new Trapp2(CVector3D(m_scroll.x + 2000, 1000, -30)));
		}
		//���̏o������
		m_cnt = Utility::Rand(60, 180);
	}
}