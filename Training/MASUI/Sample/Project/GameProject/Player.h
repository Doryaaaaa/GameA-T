#pragma once
#include"CharaBase.h"

class Player : public CharaBase
{
//�����ȊO�̊O������A�N�Z�X������
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
	~Player();

	//���S�������̏���
	void Death();

	//�X�V����
	void Update() override;
	//�`�揈��
	void Render() override;

//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
//�����o�[�ϐ��͊�{private
private:
	//CVector2D m_pos;      //�v���C���[�̍��W
	TexAnimData* mp_animDeta;   //�A�j���[�V�����̃f�[�^
	CImage* mp_image;     //�v���C���[�̉摜
	//int m_hp;             //�v���C���[��HP

//�����Ǝ��N���X���p�����N���X�ŃA�N�Z�X�o����
protected:

};