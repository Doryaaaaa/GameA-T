#pragma once
class EnemyHp {
public:
	//�Q�[�W�p�摜
	CImage m_img;
	//�Q�[�W�̕�
	int width;
	//�Q�[�W�̍���
	int height;
	//���݂�HP
	int hp;
	//�ő�HP
	int max_hp;
public:
	//�R���X�g���N�^
	EnemyHp(const CVector2D& pos);
	//�`��
	void UpDate();
};