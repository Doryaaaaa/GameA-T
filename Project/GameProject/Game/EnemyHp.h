#pragma once
#include "../Task/Task.h"
class EnemyHp : Task{
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
	CVector2D m_pos;
public:
	//�R���X�g���N�^
	EnemyHp(const CVector2D& pos);
	//�`��
	void Update();
	void Draw();
};