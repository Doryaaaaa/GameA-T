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
    Rect3D rect = Rect3D(
        m_pos.x + m_rect.left,
        m_pos.y + m_rect.top,
        m_pos.z + m_rect.front,
        m_pos.x + m_rect.right,
        m_pos.y + m_rect.bottom,
        m_pos.z + m_rect.back);
    Utility::DrawQuad(
        GetScreenPos(CVector3D(rect.left,rect.top,m_pos.z)),
        CVector2D(rect.width, rect.height),
        CVector4D(1, 0, 0, 0.5f));
}

bool ObjectBase::CollisionRect(ObjectBase* b1, ObjectBase* b2)
{
    //b1の矩形
    Rect3D rect1 = Rect3D(
        b1->m_pos.x + b1->m_rect.left,
        b1->m_pos.y + b1->m_rect.top,
        b1->m_pos.z + b1->m_rect.front,
        b1->m_pos.x + b1->m_rect.right,
        b1->m_pos.y + b1->m_rect.bottom,
        b1->m_pos.z + b1->m_rect.back);
    //b2の矩形
    Rect3D rect2 = Rect3D(
        b2->m_pos.x + b2->m_rect.left,
        b2->m_pos.y + b2->m_rect.top,
        b2->m_pos.z + b2->m_rect.front,
        b2->m_pos.x + b2->m_rect.right,
        b2->m_pos.y + b2->m_rect.bottom,
        b2->m_pos.z + b2->m_rect.back);

    //矩形同士の判定
    if (rect1.left <= rect2.right && rect1.right >= rect2.left &&
        rect1.top <= rect2.bottom && rect1.bottom >= rect2.top &&
        rect1.front<= rect2.back && rect1.back >= rect2.front)
        return true;

    return false;
}