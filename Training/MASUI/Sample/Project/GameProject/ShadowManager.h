#pragma once
#include"Task.h"

class ShadowManager : public Task
{
public:
	//�R���X�g���N�^
	ShadowManager();
	//�f�X�g���N�^
	~ShadowManager();

	//�X�V
	void Update() override;
	//�`��
	void Render() override;

private:
	CImage* mp_image;     //�e�̉摜�f�[�^
};