#pragma once
#include"ObjectBase.h"
//キャラクターベースクラス
class CharaBase : public ObjectBase
{
public:
	/// <summary>
	///コンストラクタ 
	/// </summary>
	/// <param name="pos">初期位置</param>
	CharaBase(const CVector2D& pos);
	
	//デストラクタ
	virtual ~CharaBase();

	/// <summary>
	/// ダメージを受ける
	/// </summary>
	/// <param name="damege">受けるダメージ量</param>
	void TakeDamege(int damege);

	//死亡した時の処理
	virtual void Death();

protected:
	int m_hp;        //キャラクターの残りHP
	bool m_isDeath;  //キャラクターが死亡しているかどうか
};