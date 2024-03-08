#include"ShadowManager.h"
#include"TaskManager.h"
#include"ObjectBase.h"

//�R���X�g���N�^
ShadowManager::ShadowManager()
	:Task((int)TaskPrio::Shadow)
	,mp_image(nullptr)
{
	//�e�̉摜��ǂݍ���
	mp_image = CImage::CreateImage("Shadow.png");
	mp_image->SetCenter(52.0f,16.0f);
}

//�f�X�g���N�^
ShadowManager::~ShadowManager()
{
	//�e�̉摜�f�[�^������
	delete mp_image;
}

//�X�V
void ShadowManager::Update()
{

}

//�`��
void ShadowManager::Render()
{
	//�I�u�W�F�N�g���X�g���擾
	auto& objects = TaskManager::GetObjctList();
	for (Task* task : objects)
	{
		ObjectBase* obj = dynamic_cast<ObjectBase*>(task);
		if (obj == nullptr)continue;

		//�e�I�u�W�F�N�g�̍��W�ɉe�̉摜��`��
		mp_image->SetPos(obj->GetPos());
		mp_image->Draw();
	}
}