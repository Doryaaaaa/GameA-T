#pragma once
#include"CharaBase.h"

class Player:public CharaBase {
	//�����ȊO�̊O������A�N�Z�X������
public:
	//�R���X�g���N�^
	Player();
	//�f�X�g���N�^
~Player();
	/// <summary>
	/// �v���C���[�̍��W���擾
	/// </summary>
	/// <returns>�v���C���[�̍��W</returns>
void Death()override;
const CVector2D& GetPos() const;
	/// <summary>
	/// �v���C���[�̍��W��ݒ�
	/// </summary>
	/// <param name="pos">�ݒ肷����W</param>
	void SetPos(const CVector2D& pos);
	//�X�V����
	void Update()override;
	//�`�揈��
	void Render()override;

	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
private:
	//CVector2D m_pos;//�v���C���[�̍��W
	TexAnimData* m_animData;
	CImage* m_img;//�v���C���[�̍��W
	//int m_hp;//�v���C���[�̗̑�

//�����Ǝ��N���X�p�������N���X�ŃA�N�Z�X�ł���
protected:

};
