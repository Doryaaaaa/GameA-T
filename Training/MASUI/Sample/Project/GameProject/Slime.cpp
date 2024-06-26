#include"Slime.h"
//コンストラクタ
Slime::Slime(int type,const CVector2D& pos)
	: CharaBase(pos)
	, m_type(type)
{
	m_hp = 50;

	//アニメーションデータを生成
	int frame = 6;
	mp_animDeta = new TexAnimData[1]
	{
		{
			new TexAnim[4]
			{
				{ 0, frame}, { 1, frame}, 
		        { 2, frame}, { 3, frame},
			},
			4
		},
	};
	//画像を読み込み
	std::string imagePath;
	if (m_type == 0) imagePath = "slime_a.png";
	else if (m_type == 1) imagePath = "slime_b.png";
	else if (m_type == 2) imagePath = "slime_c.png";
	mp_image = CImage::CreateImage
	(
		imagePath.c_str(),      //画像ファイルのパス
		mp_animDeta,       //アニメーションのデータ
		256.0f, 256.0f      //１コマの幅と高さ
	);
	mp_image->ChangeAnimation(0);
	mp_image->SetCenter(128.0f, 184.0f);
	mp_image->SetFlipH(true);
}

//デストラクタ
Slime::~Slime()
{
	//アニメーションのデータの配列を削除
	for (int i = 0; i < 1; i++)
	{
		delete[]mp_animDeta[i].pData;
	}
	delete[]mp_animDeta;

	//画像データを削除
	delete mp_image;
}

// 更新処理
void Slime::Update()
{
	//イメージに座標を設定して、アニメーションを更新
	mp_image->SetPos(m_pos);
	mp_image->UpdateAnimation();
}

// 描画処理
void Slime::Render()
{
	mp_image->Draw();
}