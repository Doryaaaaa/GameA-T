#include "ObjectBase.h"

CVector3D ObjectBase::m_scroll(0, 0, 0);
ObjectBase::ObjectBase(int type)
    :Task(type, (int)TaskPrio::Object)
    , m_pos(0, 0, 0)
{
}

ObjectBase::~ObjectBase()
{

}

void ObjectBase::Update()
{

}

void ObjectBase::Draw()
{

}

void ObjectBase::Collision(ObjectBase* b)
{

}

CVector2D ObjectBase::GetScreenPos(const CVector3D& pos)
{
    return CVector2D(pos.x - m_scroll.x - pos.z, pos.y - m_scroll.y + pos.z);;
}

void ObjectBase::DrawRect()
{
    //デバッグ用　矩形の表示
    CRect rect = CRect(
        m_pos.x + m_rect.m_left,
        m_pos.y + m_rect.m_top,
        m_pos.x + m_rect.m_right,
        m_pos.y + m_rect.m_bottom);
    Utility::DrawQuad(
        GetScreenPos(CVector3D(rect.m_left,rect.m_top,m_pos.z)),
        CVector2D(rect.m_width, rect.m_height),
        CVector4D(1, 0, 0, 0.5f));
}

bool ObjectBase::CollisionRect(ObjectBase* b1, ObjectBase* b2)
{
    //b1の矩形
    CRect rect1 = CRect(
        b1->m_pos.x + b1->m_rect.m_left,
        b1->m_pos.y + b1->m_rect.m_top,
        b1->m_pos.x + b1->m_rect.m_right,
        b1->m_pos.y + b1->m_rect.m_bottom);
    //b2の矩形
    CRect rect2 = CRect(
        b2->m_pos.x + b2->m_rect.m_left,
        b2->m_pos.y + b2->m_rect.m_top,
        b2->m_pos.x + b2->m_rect.m_right,
        b2->m_pos.y + b2->m_rect.m_bottom);

    //矩形同士の判定
    if (rect1.m_left <= rect2.m_right && rect1.m_right >= rect2.m_left &&
        rect1.m_top <= rect2.m_bottom && rect1.m_bottom >= rect2.m_top)
        return true;

    return false;
}