#pragma once
class Slime {
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
	/// <summary>
	/// スライムの座標を取得
	/// </summary>
	/// <returns>スライムの座標</returns>
	const CVector2D& GetPos()const;
	/// <summary>
	/// スライムの座標を設定
	/// </summary>
	/// <param name="pos">設定する座標</param>
	void SetPos(const CVector2D& pos);
	//更新処理
	void Update();
	//描画処理
	void Render();

	//自分自身のクラスしかアクセスできない
private:
	CVector2D m_pos;//スライムの座標
	TexAnimData* m_animData;
	CImage* m_img;//スライムの座標
	int m_hp;//スライムの体力
	int m_type;
//自分と自クラス継承したクラスでアクセスできる
protected:

};