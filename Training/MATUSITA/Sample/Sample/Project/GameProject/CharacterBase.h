#pragma once
#include "ObjectBase.h"

//�L�����̃x�[�X�N���X
class CharaBase :public ObjectBase {
public:
	CharaBase(const CVector2D& pos);

	virtual ~CharaBase();

	/// <summary>
	/// �_���[�W���󂯂�
	/// </summary>
	/// <param name="damage">�󂯂�_���[�W��</param>
	void TakeDamage(int damage);

	virtual void Death();
protected:
	int m_hp;
	bool m_isDeath;
};