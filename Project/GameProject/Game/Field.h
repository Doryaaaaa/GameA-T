#pragma once
#include "../Base/Base.h"

class Field :public Base {
public:
	//画像オブジェクト
	CImage m_field;
public:
	//コンストラクタ
	Field();
	//描画
	void Draw();
};