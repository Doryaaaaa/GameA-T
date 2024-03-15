#include "Trapp1Manager.h"
#include "Trapp1.h"
#include "Trapp2.h"

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
		switch (rand()%2)
		{
		case 0:
			(new Trapp1(CVector3D(m_scroll.x + Utility::Rand(2000.0f, 2500.0f), 900, -390)));
			break;
		case 1:
			int m_rcnt;
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
			break;
			
		}

		//X����12�`1800�̊ԂŃ����_��
		

		//���̏o������
		m_cnt = Utility::Rand(40, 120);
	}
}