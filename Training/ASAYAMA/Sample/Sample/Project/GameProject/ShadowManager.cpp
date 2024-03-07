#include"ShadowManager.h"
#include"TaskManager.h"
#include"ObjectBase.h"

//�R���X�g���N�^
ShadowManager::ShadowManager()
	:Task((int)TaskPrio::Shadow)
	,mp_image(nullptr)
{
	//�A�̉摜��ǂݍ���
	mp_image = CImage::CreateImage("shadow.png");
	mp_image->SetCenter(52.0f, 16.0f);
}
//�f�X�g���N�^
ShadowManager::~ShadowManager() {
	//�A�̃f�[�^���폜
	delete mp_image;
}
//�X�V
void ShadowManager::Update() {

}
//�`��
void ShadowManager::Render() {
	//�I�u�W�F�N�g���X�g���擾
	auto& objects = TaskManager::GetObjectList(); {
		for (Task* task : objects) {
			ObjectBase* obj = dynamic_cast<ObjectBase*>(task);
			if (obj == nullptr)continue;
			//�e�I�u�W�F�N�g�̍��W�ɉA�̉摜��`��
			mp_image->SetPos(obj->GetPos());
			mp_image->Draw();
		}
	}
}