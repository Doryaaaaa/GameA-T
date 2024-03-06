#include "Field.h"

Field::Field() :Base(eType_Field)
{
	m_field = COPY_RESOURCE("Field", CImage);
}
void Field::Draw()
{
	float sc;
	m_field.Draw();
	sc = m_scroll.x / 4;
	m_field.SetRect(sc, 0, sc + 1920,1080);
	m_field.Draw();
}