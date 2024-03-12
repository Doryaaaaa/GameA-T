#include "Portion1.h"

Portion1Manager::Portion1Manager() : ObjectBase(eType_Portion1Manager)
{
	//アイテム出現までの時間
	m_cnt = 0;
}

void Portion1Manager::Update()
{
	m_cnt--;
	//アイテム出現
	if (m_cnt <= 0) {
		//X軸は2000～2500の間、Y軸は500～1080の間でランダム
		(new Portion1(CVector2D(m_scroll.x + Utility::Rand(2000.0f, 2500.0f), Utility::Rand(500.0f, 1080.0f))));
		//次の出現時間
		m_cnt = Utility::Rand(40, 120);
	}
}

Portion1::Portion1(const CVector3D& pos) :ObjectBase(eType_Portion1) {
	m_img= COPY_RESOURCE("Portion1", CImage);
	m_pos=pos;
	//サイズ
	m_img.SetSize(200,200);
	//中心位置
	m_img.SetCenter(50, 0);
	//当たり判定
	m_rect = CRect(50, 50, 50, 50);
}

void Portion1::Update()
{

}

void Portion1::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	Utility::DrawQuad(
        GetScreenPos(m_pos),
        CVector2D(100,200),
        CVector4D(1, 0, 0, 0.5f));
	DrawRect();
}
