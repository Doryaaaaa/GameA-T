#pragma once
#include"CharaBase.h"
class Slime :public CharaBase{
	//自分以外の外部からアクセスし放題
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
	const CVector2D& GetPos() const;
	/// <summary>
	/// スライムの座標を設定
	/// </summary>
	/// <param name="pos">設定する座標</param>
	void SetPos(const CVector2D& pos);
	//自分自身のクラスしかアクセスできない
private:
	TexAnimData* m_animData;
	CImage* m_img;//画像
	int m_type;//スライムの種類
//自分と自クラス継承したクラスでアクセスできる
protected:

};