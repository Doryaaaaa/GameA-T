#pragma once
#include "../Task/Task.h"

class Field :public Task {
public:
	//�摜�I�u�W�F�N�g
	CImage m_field;
	CImage m_img;
	int m_pos_y;
public:
	//�R���X�g���N�^
	Field();
	//�`��
	void Draw();
	int GetGroundY() {
		return m_pos_y;
	}
};