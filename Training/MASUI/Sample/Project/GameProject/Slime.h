#pragma once
#include"CharaBase.h"

class Slime : CharaBase
{
public:
	/// <summary>
	/// コンストラクタ
	/// </summary>
	/// <param name="type">スライムの種類</param>
	/// <param name="pos">初期位置</param>
	Slime(int type,const CVector2D& pos);
	//デストラクタ
	~Slime();

	//更新処理
	void Update() override;
	//描画処理
	void Render() override;

	//自分自身のクラスしかアクセスできない
	//メンバー変数は基本private
private:
	//CVector2D m_pos;            //座標
	TexAnimData* mp_animDeta;   //アニメーションのデータ
	CImage* mp_image;           //画像
	//int m_hp;                   //HP
	int m_type;                 //スライムの種類

	//自分と自クラスを継承下クラスでアクセス出来る
protected:
};