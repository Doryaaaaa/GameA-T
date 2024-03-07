#include "Field.h"

Field::Field() :Base(eType_Field)
{
	m_field = COPY_RESOURCE("Field", CImage);
	//’†SˆÊ’uİ’è
	m_img.SetCenter(100, 100);
	//“–‚½‚è”»’è
	m_rect = CRect(1000, -1000, 1000, 1000);
	m_pos_y = 1000;
}
void Field::Draw()
{
	float sc;
	m_field.Draw();
	sc = m_scroll.x / 4;
	m_field.SetRect(sc, 0, sc + 1920,1080);
	DrawRect();
	m_field.Draw();
}