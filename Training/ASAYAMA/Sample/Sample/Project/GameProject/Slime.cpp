#include"Slime.h"
//コンストラクタ
Slime::Slime(int type, const CVector2D& pos)
   :CharaBase(pos)
   ,m_type(type)
{
	m_hp = 100;
	int frame = 6;
	m_animData = new TexAnimData[1]
	{
		{
		new TexAnim[4]
		{
			{0,frame},{1,frame},
		    {2,frame},{3,frame},
			},
			4
	},
	};
	std::string imagePath;
	if (m_type == 0)imagePath = "slime_a.png";
	else if (m_type == 1)imagePath = "slime_b.png";
	else if (m_type == 2)imagePath = "slime_c.png";
		m_img = CImage::CreateImage
	(imagePath.c_str(),
		m_animData,
		256.0f, 256.0f);
	m_img->ChangeAnimation(0);
	m_img->SetCenter(128.0f, 184.0f);
	m_img->SetFlipH(true);
}
//デストラクタ
Slime::~Slime() {
	for (int i = 0; i < 1; i++) {
		delete[]m_animData[i].pData;
	}
	delete[]m_animData;
	//画像データを削除
	delete m_img;
}
const CVector2D& Slime::GetPos()const {
	return m_pos;
}
void Slime::SetPos(const CVector2D& pos) {
	m_pos = pos;
}
//更新処理
void Slime::Update() {
	m_img->SetPos(m_pos);
	m_img->UpdateAnimation();
}
//描画処理
void Slime::Render() {
	m_img->Draw();
}