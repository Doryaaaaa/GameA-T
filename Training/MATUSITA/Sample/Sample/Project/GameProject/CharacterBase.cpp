#include "CharacterBase.h"

CharaBase::CharaBase(const CVector2D&pos)
	:ObjectBase(pos)
	,m_hp(100)
	,m_isDeath(false)
{

}

CharaBase::~CharaBase()
{

}
//ダメージを受ける
void CharaBase::TakeDamage(int damage) {
	//既にHPが0ならダメージ処理されない
	if (m_hp <= 0) return;

	//ダメージ計算
	m_hp -= damage;
	//もし０なら
	if (m_hp <= 0) {
		//死亡
		Death();
	}
}
//死亡した時の処理
void CharaBase::Death() {
	//死亡フラグを立てる
	m_isDeath = true;
}