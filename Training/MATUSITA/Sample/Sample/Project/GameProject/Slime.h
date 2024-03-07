#pragma once
#include "CharacterBase.h"

class Slime :public CharaBase {
	//�����ȊO�̊O�����A�N�Z�X�ł���
public:
	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	/// <param name="type">�X���C���̎��</param>
	/// <param name="pos">�����ʒu</param>
	Slime(int type,const CVector2D& pos);
	//�f�X�g���N�^
	~Slime();


	//�X�V����
	void Update()override;

	//�`�揈��
	void Render()override;

	//�������g�̂�
	//�����o�ϐ�
private:
	TexAnimData* mp_animData; //�A�j���[�V�����̃f�[�^
	CImage* mp_image; //�摜
	int m_type; //�X���C���̎��

//�����Ǝ��N���X���p�������N���X���A�N�Z�X�ł���
protected:
};
