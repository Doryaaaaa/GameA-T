#pragma once
class Player
{
//�A�N�Z�X�C
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
	const CVector2D& GetPos() const;

	/// <summary>
	/// �v���C���[�̍��W��ݒ�
	/// </summary>
	/// <param name="pos">�ݒ肷����W</param>
	void SetPos(const CVector2D& pos);

	//�X�V����
	void Update();
	//
	void Render();

//�������g�̃N���X�����A�N�Z�X�ł��Ȃ�
//�����o�[�ϐ��͊�{private
private:
	CVector2D m_pos;      //�v���C���[�̍��W
	TexAnimData* mp_animDeta;   //�A�j���[�V�����̃f�[�^
	CImage* mp_image;     //�v���C���[�̉摜
	int m_hp;             //�v���C���[��HP

//�����Ǝ��N���X���p�����N���X�ŃA�N�Z�X�o����
protected:

};