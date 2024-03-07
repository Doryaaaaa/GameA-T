#pragma once
#include "ObjectBase.h"

//キャラのベースクラス
class CharaBase :public ObjectBase {
public:
	CharaBase(const CVector2D& pos);

	virtual ~CharaBase();

	/// <summary>
	/// ダメージを受ける
	/// </summary>
	/// <param name="damage">受けるダメージ量</param>
	void TakeDamage(int damage);

	virtual void Death();
protected:
	int m_hp;
	bool m_isDeath;
};