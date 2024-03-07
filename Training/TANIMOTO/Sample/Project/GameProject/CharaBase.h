#pragma once
#include "ObjectBase.h"

// キャラクターのベースクラス
class CharaBase : public ObjectBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="pos">初期位置</param>
	CharaBase(const CVector2D& pos);
	// デストラクタ
	virtual ~CharaBase();

	/// <summary>
	/// ダメージを受ける
	/// </summary>
	/// <param name="damage">受けるダメージ量</param>
	void TakeDamage(int damage);

	// 死亡した時の処理
	virtual void Death();
	
protected:
	int m_hp;		// キャラクターの残りHP
	bool m_isDeath;	// キャラクターが死亡しているかどうか
};