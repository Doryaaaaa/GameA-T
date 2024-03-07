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
	void Render() override;

private:
	CImage* mp_image;     //影の画像データ
};