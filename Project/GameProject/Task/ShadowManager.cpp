#include"ShadowManager.h"
#include"TaskManager.h"
#include"ObjectBase.h"

//コンストラクタ
ShadowManager::ShadowManager()
	:Task(eTyp_ShadowManager,(int)TaskPrio::Shadow)
{
	
	//影の画像を読み込む
	m_img = COPY_RESOURCE("ShadowManager", CImage);
}

//デストラクタ
ShadowManager::~ShadowManager()
{
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
		if (obj == nullptr || !task->m_isShadow)continue;

		//各オブジェクトの座標に影の画像を描画
		m_img.SetPos(obj->GetScreenPos(CVector3D(obj->m_pos.x,1000, obj->m_pos.z)));
		m_img.SetSize(task->m_ShadowSize, 40);
		m_img.SetCenter(task->m_ShadowCenter, 20);
		m_img.Draw();
	}
}