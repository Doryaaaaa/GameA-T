#pragma once
#include"CharaBase.h"

class Slime : CharaBase
{
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
	void Update() override;
	//�`�揈��
	void Render() override;

	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
	//�����o�[�ϐ��͊�{private
private:
	//CVector2D m_pos;            //���W
	TexAnimData* mp_animDeta;   //�A�j���[�V�����̃f�[�^
	CImage* mp_image;           //�摜
	//int m_hp;                   //HP
	int m_type;                 //�X���C���̎��

	//�����Ǝ��N���X���p�����N���X�ŃA�N�Z�X�o����
protected:
};