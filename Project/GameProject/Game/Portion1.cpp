#include "Portion1.h"

Portion1::Portion1(const CVector3D& pos) :Base(eType_Portion1) {
	m_img= COPY_RESOURCE("Portion1", CImage);
	m_pos=pos;
	m_img.SetSize(250,250);
	m_rect = CRect(0, 0, 0, 0);
}

void Portion1::Update()
{

}

void Portion1::Drow()
{

}
