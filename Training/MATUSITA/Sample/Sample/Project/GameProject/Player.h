#pragma once
#include "CharacterBase.h"

class Player:public CharaBase
{

//�����ȊO�̊O�����A�N�Z�X�ł���
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	void Death() override;

	//�X�V����
	void Update() override;

	//�`�揈��
	void Render()override;

//�������g�̂�
//�����o�ϐ�
private:
	TexAnimData* mp_animData; //�A�j���[�V�����̃f�[�^
	CImage* mp_image; //�v���C���[�̉摜

//�����Ǝ��N���X���p�������N���X���A�N�Z�X�ł���
protected:
};
