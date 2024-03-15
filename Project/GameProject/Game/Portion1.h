#pragma once
#include "../Task/ObjectBase.h"

class Portion1Manager : public ObjectBase {
private:
	int m_cnt;
	//どのラインに配置するかの数
	int m_rcnt;
public:
	Portion1Manager();
	void Update();
};

//加速薬
class Portion1 :public ObjectBase{
private:
		CImage m_img;
		bool m_is_portion1;

public:
		Portion1(const CVector3D& pos);
		void Update();
		void Draw();

};



