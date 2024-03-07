#include"CharaBase.h"

//コンストラクタ
CharaBase::CharaBase(const CVector2D& pos)
:ObjectBase(pos)
,m_hp(100)
,m_isDeath(false)
{

}

//デストラクタ
CharaBase::~CharaBase()
{

}

//ダメージを受ける
void CharaBase::TakeDamege(int damage)
{
	//既にHPが0であれば、ダメージ処理を実行市内
	if (m_hp <= 0)return;
	//起こりHPからダメージ分減算
	m_hp = damage;
	//残りHPが0であれば
	if (m_hp <= 0)
	{
		//死亡処理
		Death();
	}
}

//死亡下時の処理
void CharaBase::Death()
{
	//死亡フラグを立てる
	m_isDeath = true;
}