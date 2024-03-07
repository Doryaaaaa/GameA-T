#include "ObjectBase.h"

// コンストラクタ
ObjectBase::ObjectBase(const CVector2D& pos)
	: Task((int)TaskPrio::Object)
	,m_pos(pos)
{
}

// デストラクタ
ObjectBase::~ObjectBase()
{
}

// オブジェクトの座標を設定
void ObjectBase::SetPos(const CVector2D& pos)
{
	m_pos = pos;
}

// オブジェクトの座標を取得
const CVector2D& ObjectBase::GetPos() const
{
	return m_pos;
}
