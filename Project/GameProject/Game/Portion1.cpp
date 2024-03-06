#include "Portion1.h"

Portion1::Portion1(const CVector3D& pos) :Base(eType_Portion1) {
	m_img= COPY_RESOURCE("Portion1", CImage);
	m_pos=pos;
	m_img.SetSize(500,500);
	m_rect = CRect(0, 0, 0, 0);
}

void Portion1::Update()
{

}

void Portion1::Drow()
{
	m_img.SetPos(m_pos.x, m_pos.y);
	m_img.Draw();
	//DrawRect();
}

