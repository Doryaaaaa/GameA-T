#pragma once
#include"CharaBase.h"

class Player : public CharaBase
{
//自分以外の外部からアクセスし放題
public:
	//コンストラクタ
	Player();
	//デストラクタ
	~Player();

	//死亡した時の処理
	void Death();

	//更新処理
	void Update() override;
	//描画処理
	void Render() override;

//自分自身のクラスしかアクセスできない
//メンバー変数は基本private
private:
	//CVector2D m_pos;      //プレイヤーの座標
	TexAnimData* mp_animDeta;   //アニメーションのデータ
	CImage* mp_image;     //プレイヤーの画像
	//int m_hp;             //プレイヤーのHP

//自分と自クラスを継承下クラスでアクセス出来る
protected:

};