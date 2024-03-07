#include"CharaBase.h"

CharaBase::CharaBase(const CVector2D& pos)
: ObjectBase(pos)
		,m_hp(100)
		,m_isDeath(false)
{

}
//デストラクタ
CharaBase::~CharaBase() {

}
//ダメージを受ける
void CharaBase::TakeDamage(int damage) {
	//すでにHPが０であれば、ダメージ処理を実行しない
	if (m_hp <= 0)return;
	//残りHPからダメージ分減算
	m_hp -= damage;
	//残りHPが０であれば
	if (m_hp <= 0) {
		//死亡処理
		Death();
	}
}
//死亡した時の処理
void CharaBase::Death() {
	//死亡フラグを立てる
	m_isDeath = true;
}