#pragma once
#include "CharacterBase.h"

class Slime :public CharaBase {
	//自分以外の外部もアクセスできる
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
	void Update()override;

	//描画処理
	void Render()override;

	//自分自身のみ
	//メンバ変数
private:
	TexAnimData* mp_animData; //アニメーションのデータ
	CImage* mp_image; //画像
	int m_type; //スライムの種類

//自分と自クラスを継承したクラスがアクセスできる
protected:
};
