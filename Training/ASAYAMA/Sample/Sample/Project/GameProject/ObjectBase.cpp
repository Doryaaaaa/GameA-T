#include"ObjectBase.h"

ObjectBase::ObjectBase(const CVector2D& pos)
:Task((int)TaskPrio::Object)
,m_pos(pos) {

}
ObjectBase::~ObjectBase() {

}
void ObjectBase::SetPos(const CVector2D& pos) {
		m_pos = pos;
}
const CVector2D& ObjectBase::GetPos()const{
	return m_pos;
}

