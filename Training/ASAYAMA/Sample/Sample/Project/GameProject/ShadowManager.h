#pragma once
#include"Task.h"
//�S�Ă̂��Ԃ��W�F�N�g�̉e��`�悷��
class ShadowManager :public Task {
public:
	//�R���X�g���N�^
	ShadowManager();
	//�f�X�g���N�^
	~ShadowManager();
	//�X�V
	void Update()override;
	//�`��
	void Render()override;
private:
	CImage* mp_image;//�A�̉摜�f�[�^
};