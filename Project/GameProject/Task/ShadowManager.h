#pragma once
#include"Task.h"

class ShadowManager : public Task
{
public:
	//コンストラクタ
	ShadowManager();
	//デストラクタ
	~ShadowManager();

	//更新
	void Update() override;
	//描画
	void Draw() override;

private:
	CImage m_img;     //影の画像データ
};