#include "Portion1.h"

Portion1Manager::Portion1Manager() : ObjectBase(eType_Portion1Manager)
{
	//アイテム出現までの時間
	m_cnt = 0;
}

void Portion1Manager::Update()
{
	//アイテムが画面外（左）にいったら消す
		/*if (m_pos.x < m_scroll.x - 600) {
			Kill();
		}*/
	m_cnt--;
	//アイテム出現
	if (m_cnt <= 0) {
		//どこに配置するためのランダムな数字
		m_rcnt= Utility::Rand(0,300);

		if (m_rcnt < 100) {
			//X軸はスクロール値＋2000の間、Y軸は1000の間,Z軸は-310～0の間でランダム
			//アイテム出現　上
			(new Portion1(CVector3D(m_scroll.x+2000,1000,-310)));
		}
		else if (m_rcnt < 200) {
			//X軸はスクロール値＋2000の間、Y軸は1000の間,Z軸は-170～0の間でランダム
			//アイテム出現　真ん中
			(new Portion1(CVector3D(m_scroll.x + 2000, 1000, -170)));
		}
		else {
			//アイテム出現 下
			//X軸はスクロール値＋2000の間、Y軸は1000の間,Z軸は-30～0の間でランダム
			(new Portion1(CVector3D(m_scroll.x + 2000, 1000, -30)));
		}

		//X軸は2000～2500の間、Y軸は1000の間,Z軸は-380～0の間でランダム
		(new Portion1(CVector3D(m_scroll.x + Utility::Rand(2000.0f, 2500.0f),1000, Utility::Rand(-380.0f,0.0f))));

		//次の出現時間
		m_cnt = Utility::Rand(60, 180);

		

	}
}

Portion1::Portion1(const CVector3D& pos) :ObjectBase(eType_Portion1) {
	m_img= COPY_RESOURCE("Portion1", CImage);
	m_pos=pos;
	//サイズ
	m_img.SetSize(200,200);
	//中心位置
	m_img.SetCenter(100,180);
	//当たり判定
	m_rect = Rect3D(-70, -50,-10, 70, 0,10);
	m_isShadow = true;
	m_ShadowSize = 100;
	m_ShadowCenter = 50;
}

void Portion1::Update()
{

}

void Portion1::Draw()
{
	m_img.SetPos(GetScreenPos(m_pos));
	m_img.Draw();
	/*Utility::DrawQuad(
        GetScreenPos(m_pos),
        CVector2D(16,16),
        CVector4D(1, 0, 0, 0.5f));*/
	//DrawRect();
}
