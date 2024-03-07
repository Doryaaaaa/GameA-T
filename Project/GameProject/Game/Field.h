#pragma once
#include "../Base/Base.h"

class Field :public Base {
public:
	//画像オブジェクト
	CImage m_field;
	CImage m_img;
	int m_pos_y;
public:
	//コンストラクタ
	Field();
	//描画
	void Draw();
	int GetGroundY() {
		return m_pos_y;
	}
};