#pragma once
#include"CharaBase.h"
class Slime :public CharaBase{
	//�����ȊO�̊O������A�N�Z�X������
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
	const CVector2D& GetPos() const;
	/// <summary>
	/// �X���C���̍��W��ݒ�
	/// </summary>
	/// <param name="pos">�ݒ肷����W</param>
	void SetPos(const CVector2D& pos);
	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
private:
	TexAnimData* m_animData;
	CImage* m_img;//�摜
	int m_type;//�X���C���̎��
//�����Ǝ��N���X�p�������N���X�ŃA�N�Z�X�ł���
protected:

};