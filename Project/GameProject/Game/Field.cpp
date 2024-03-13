#include "Field.h"
#include"Task/ObjectBase.h"
Field::Field() :Task(eType_Field, (int)TaskPrio::Field)
{
	m_field = COPY_RESOURCE("Field", CImage);
	//íÜêSà íuê›íË
	m_img.SetCenter(100, 100);
	m_pos_y = 1000;
}
void Field::Draw()
{
	float sc;
	m_field.Draw();
	sc = ObjectBase::m_scroll.x;
	m_field.SetRect(sc, 0, sc + 1920,1080);
	m_field.Draw();
}
