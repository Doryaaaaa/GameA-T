#pragma once
#include "CharacterBase.h"

class Player:public CharaBase
{

//自分以外の外部もアクセスできる
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	void Death() override;

	//更新処理
	void Update() override;

	//描画処理
	void Render()override;

//自分自身のみ
//メンバ変数
private:
	TexAnimData* mp_animData; //アニメーションのデータ
	CImage* mp_image; //プレイヤーの画像

//自分と自クラスを継承したクラスがアクセスできる
protected:
};
