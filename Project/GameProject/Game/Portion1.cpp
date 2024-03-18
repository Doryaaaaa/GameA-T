#include "Portion1.h"

Portion1Manager::Portion1Manager() : ObjectBase(eType_Portion1Manager)
{
	//�A�C�e���o���܂ł̎���
	m_cnt = 0;
}

void Portion1Manager::Update()
{
	//�A�C�e������ʊO�i���j�ɂ����������
		/*if (m_pos.x < m_scroll.x - 600) {
			Kill();
		}*/
	m_cnt--;
	//�A�C�e���o��
	if (m_cnt <= 0) {
		//�ǂ��ɔz�u���邽�߂̃����_���Ȑ���
		m_rcnt= Utility::Rand(0,300);

		if (m_rcnt < 100) {
			//X���̓X�N���[���l�{2000�̊ԁAY����1000�̊�,Z����-310�`0�̊ԂŃ����_��
			//�A�C�e���o���@��
			(new Portion1(CVector3D(m_scroll.x+2000,1000,-310)));
		}
		else if (m_rcnt < 200) {
			//X���̓X�N���[���l�{2000�̊ԁAY����1000�̊�,Z����-170�`0�̊ԂŃ����_��
			//�A�C�e���o���@�^��
			(new Portion1(CVector3D(m_scroll.x + 2000, 1000, -170)));
		}
		else {
			//�A�C�e���o�� ��
			//X���̓X�N���[���l�{2000�̊ԁAY����1000�̊�,Z����-30�`0�̊ԂŃ����_��
			(new Portion1(CVector3D(m_scroll.x + 2000, 1000, -30)));
		}

		//X����2000�`2500�̊ԁAY����1000�̊�,Z����-380�`0�̊ԂŃ����_��
		(new Portion1(CVector3D(m_scroll.x + Utility::Rand(2000.0f, 2500.0f),1000, Utility::Rand(-380.0f,0.0f))));

		//���̏o������
		m_cnt = Utility::Rand(60, 180);

		

	}
}

Portion1::Portion1(const CVector3D& pos) :ObjectBase(eType_Portion1) {
	m_img= COPY_RESOURCE("Portion1", CImage);
	m_pos=pos;
	//�T�C�Y
	m_img.SetSize(200,200);
	//���S�ʒu
	m_img.SetCenter(100,180);
	//�����蔻��
	m_rect = Rect3D(-70, -50,-10, 70, 0,10);
	m_isShadow = true;
	m_ShadowSize = 100;
	m_ShadowCenter = 50;
}

void Portion1::Update()
{

}

void Portion1::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	/*Utility::DrawQuad(
        GetScreenPos(m_pos),
        CVector2D(16,16),
        CVector4D(1, 0, 0, 0.5f));*/
	//DrawRect();
}
