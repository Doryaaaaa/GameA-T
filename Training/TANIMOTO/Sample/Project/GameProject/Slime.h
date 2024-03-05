#pragma once

class Slime
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

	/// <summary>
	/// 座標を取得
	/// </summary>
	/// <returns>座標</returns>
	const CVector2D& GetPos() const;

	/// <summary>
	/// 座標を設定
	/// </summary>
	/// <param name="pos">設定する座標</param>
	void SetPos(const CVector2D& pos);

	// 更新処理
	void Update();
	// 描画処理
	void Render();

	//自分自身のクラスしかアクセスできない
	//メンバ変数は基本private
private:
	CVector2D m_pos;	// 座標
	TexAnimData* mp_animData;	// アニメーションのデータ
	CImage* mp_image;	// 画像
	int m_hp;			// HP
	int m_type;			// スライムの種類
};