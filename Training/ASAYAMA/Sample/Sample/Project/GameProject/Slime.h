#pragma once
class Slime {
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
	/// <summary>
	/// �X���C���̍��W���擾
	/// </summary>
	/// <returns>�X���C���̍��W</returns>
	const CVector2D& GetPos()const;
	/// <summary>
	/// �X���C���̍��W��ݒ�
	/// </summary>
	/// <param name="pos">�ݒ肷����W</param>
	void SetPos(const CVector2D& pos);
	//�X�V����
	void Update();
	//�`�揈��
	void Render();

	//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
private:
	CVector2D m_pos;//�X���C���̍��W
	TexAnimData* m_animData;
	CImage* m_img;//�X���C���̍��W
	int m_hp;//�X���C���̗̑�
	int m_type;
//�����Ǝ��N���X�p�������N���X�ŃA�N�Z�X�ł���
protected:

};