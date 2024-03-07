#include "ObjectBase.h"

//コンストラクタ
ObjectBase::ObjectBase(const CVector2D& pos) : Task((int)TaskPrio::Object),m_pos(pos) {

}
//デンストラクタ
ObjectBase::~ObjectBase() {

}
//オブジェクト座標設定
void ObjectBase::SetPos(const CVector2D& pos) {
	m_pos = pos;
}
//オブジェクト座標取得
const CVector2D& ObjectBase::GetPos() const {
	return m_pos;
}

