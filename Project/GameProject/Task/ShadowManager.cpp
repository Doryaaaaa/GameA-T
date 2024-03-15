#include"ShadowManager.h"
#include"TaskManager.h"
#include"ObjectBase.h"

//�R���X�g���N�^
ShadowManager::ShadowManager()
	:Task(eTyp_ShadowManager,(int)TaskPrio::Shadow)
{
	
	//�e�̉摜��ǂݍ���
	m_img = COPY_RESOURCE("ShadowManager", CImage);
}

//�f�X�g���N�^
ShadowManager::~ShadowManager()
{
}

//�X�V
void ShadowManager::Update()
{

}

//�`��
void ShadowManager::Draw()
{
	//�I�u�W�F�N�g���X�g���擾
	auto& objects = TaskManager::GetObjctList();
	for (Task* task : objects)
	{
		ObjectBase* obj = dynamic_cast<ObjectBase*>(task);
		if (obj == nullptr || !task->m_isShadow)continue;

		//�e�I�u�W�F�N�g�̍��W�ɉe�̉摜��`��
		m_img.SetPos(obj->GetScreenPos(CVector3D(obj->m_pos.x,1000, obj->m_pos.z)));
		m_img.SetSize(task->m_ShadowSize, 40);
		m_img.SetCenter(task->m_ShadowCenter, 20);
		m_img.Draw();
	}
}