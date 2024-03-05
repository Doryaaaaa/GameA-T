#pragma once

class Player {
	//自分以外の外部からアクセスし放題
public:
	//コンストラクタ
	Player();
	//デストラクタ
~Player();
	/// <summary>
	/// プレイヤーの座標を取得
	/// </summary>
	/// <returns>プレイヤーの座標</returns>
const CVector2D& GetPos() const;
	/// <summary>
	/// プレイヤーの座標を設定
	/// </summary>
	/// <param name="pos">設定する座標</param>
	void SetPos(const CVector2D& pos);
	//更新処理
	void Update();
	//描画処理
	void Render();

	//自分自身のクラスしかアクセスできない
private:
	CVector2D m_pos;//プレイヤーの座標
	TexAnimData* m_animData;
	CImage* m_img;//プレイヤーの座標
	int m_hp;//プレイヤーの体力

//自分と自クラス継承したクラスでアクセスできる
protected:

};
