#include"ShadowManager.h"
#include"TaskManager.h"
#include"ObjectBase.h"

//コンストラクタ
ShadowManager::ShadowManager()
	:Task(eTyp_ShadowManager,(int)TaskPrio::Shadow)
{
	//影の画像を読み込む
	m_img = COPY_RESOURCE("ShadowManager", CImage);
	m_img.SetSize(200,40);
	m_img.SetCenter(100,20);
}

//デストラクタ
ShadowManager::~ShadowManager()
{
	//影の画像データを消去

}

//更新
void ShadowManager::Update()
{

}

//描画
void ShadowManager::Draw()
{
	//オブジェクトリストを取得
	auto& objects = TaskManager::GetObjctList();
	for (Task* task : objects)
	{
		ObjectBase* obj = dynamic_cast<ObjectBase*>(task);
		if (obj == nullptr)continue;

		//各オブジェクトの座標に影の画像を描画
		m_img.SetPos(obj->GetScreenPos(CVector3D(obj->m_pos.x,1000, obj->m_pos.z)));
		m_img.Draw();
	}
}