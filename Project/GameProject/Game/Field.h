#pragma once
#include "../Base/Base.h"

class Field :public Base {
public:
	//�摜�I�u�W�F�N�g
	CImage m_field;
public:
	//�R���X�g���N�^
	Field();
	//�`��
	void Draw();
};