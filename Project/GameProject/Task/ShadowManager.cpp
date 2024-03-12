#include"ShadowManager.h"
#include"TaskManager.h"
#include"ObjectBase.h"

//�R���X�g���N�^
ShadowManager::ShadowManager()
	:Task(eTyp_ShadowManager,(int)TaskPrio::Shadow)
{
	//�e�̉摜��ǂݍ���
	m_img = COPY_RESOURCE("ShadowManager", CImage);
	m_img.SetSize(200,40);
	m_img.SetCenter(100,20);
}

//�f�X�g���N�^
ShadowManager::~ShadowManager()
{
	//�e�̉摜�f�[�^������

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
		if (obj == nullptr)continue;

		//�e�I�u�W�F�N�g�̍��W�ɉe�̉摜��`��
		m_img.SetPos(obj->GetScreenPos(CVector3D(obj->m_pos.x,1000, obj->m_pos.z)));
		m_img.Draw();
	}
}