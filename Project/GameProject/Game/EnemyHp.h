#pragma once
class EnemyHp {
public:
	//ゲージ用画像
	CImage m_img;
	//ゲージの幅
	int width;
	//ゲージの高さ
	int height;
	//現在のHP
	int hp;
	//最大HP
	int max_hp;
public:
	//コンストラクタ
	EnemyHp(const CVector2D& pos);
	//描画
	void UpDate();
};