#pragma once
#include "CharaBase.h"

class Player : public CharaBase
{
//アクセス修飾子
//自分以外の外部からアクセスし放題
public:
	// コンストラクタ
	Player();
	// デストラクタ
	~Player();

	//死亡した時の処理
	void Death()override;

	// 更新処理
	void Update()override;
	// 描画処理
	void Render()override;

//自分自身のクラスしかアクセスできない
//メンバ変数は基本private
private:
	TexAnimData* mp_animData;	// アニメーションのデータ
	CImage* mp_image;	// プレイヤーの画像
};