#pragma once
#include "CharaBase.h"

class Slime : public CharaBase
{
	//アクセス修飾子
//自分以外の外部からアクセスし放題
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="type">スライムの種類</param>
	/// <param name="pos">初期位置</param>
	Slime(int type, const CVector2D& pos);
	// デストラクタ
	~Slime();

	// 更新処理
	void Update()override;
	// 描画処理
	void Render()override;

	//自分自身のクラスしかアクセスできない
	//メンバ変数は基本private
private:
	TexAnimData* mp_animData;	// アニメーションのデータ
	CImage* mp_image;	// 画像
	int m_type;			// スライムの種類
};